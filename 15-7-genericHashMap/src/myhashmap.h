#ifndef MYHASHMAP_H
#define MYHASHMAP_H

#include <climits>
#include <optional>
#include <string>

constexpr int HASH_MASK = INT_MAX;
constexpr int HASH_SEED = 5381;
constexpr int HASH_MULTIPLIER = 33;

int hashcode(std::string const &str) noexcept;

template <typename K, typename V> class HashMap {

public:
  HashMap();
  ~HashMap();
  // public member functions
  std::optional<V> get(K const &key) const noexcept;
  void put(K const &key, V const &value);
  size_t size() const noexcept { return nElements; }
  // Explicitly disable the generation of special member functions.
  HashMap(HashMap const &) = delete;
  HashMap &operator=(HashMap const &) = delete;
  HashMap(HashMap &&) = delete;
  HashMap &operator=(HashMap &&) = delete;

private:
  static constexpr int INITIAL_BUCKET_COUNT = 13;
  static constexpr double REHASH_THRESHOLD = 0.7;
  // private structures
  struct Cell {
    K key;
    V value;
    Cell *next;
  };
  // private variables
  Cell **buckets;
  int nBuckets = INITIAL_BUCKET_COUNT;
  int nElements = 0;
  // private functions
  Cell *findCell(int bucketId, K const &key) const noexcept;
  void rehash();
};

int hashcode(std::string const &str) noexcept {
  unsigned hash = HASH_SEED;
  for (auto c : str)
    hash = HASH_MULTIPLIER * hash + c;
  return static_cast<int>(hash & HASH_MASK);
}
template <typename K, typename V> HashMap<K, V>::HashMap() {
  buckets = new Cell *[nBuckets];
  for (auto i = 0; i < nBuckets; i++)
    buckets[i] = nullptr;
}

template <typename K, typename V> HashMap<K, V>::~HashMap() {
  for (auto i = 0; i < nBuckets; i++) {
    auto ptr = buckets[i];
    while (ptr != nullptr) {
      auto old = ptr;
      ptr = old->next;
      delete old;
    }
  }
}

template <typename K, typename V>
std::optional<V> HashMap<K, V>::get(const K &key) const noexcept {
  int bucketId = hashcode(key) % nBuckets;
  if (auto ptr = findCell(bucketId, key))
    return ptr->value;
  return std::optional<V>();
}

template <typename K, typename V>
void HashMap<K, V>::put(const K &key, V const &value) {
  int bucketId = hashcode(key) % nBuckets;
  auto ptr = findCell(bucketId, key);
  if (ptr != nullptr) {
    ptr->value = value;
    return;
  }
  ptr = new Cell;
  ++nElements;
  ptr->key = key;
  ptr->value = value;
  // insert it before the first Cell in the bucket.
  ptr->next = buckets[bucketId];
  buckets[bucketId] = ptr;
#if DEBUG
  std::cout << "Putting " << key << " -> " << value << std::endl;
#endif
  if (double(nElements) / nBuckets > REHASH_THRESHOLD)
    rehash();
}

template <typename K, typename V>
typename HashMap<K, V>::Cell *
HashMap<K, V>::findCell(int bucketId, const K &key) const noexcept {
  for (auto ptr = buckets[bucketId]; ptr != nullptr; ptr = ptr->next)
    if (ptr->key == key)
      return ptr;
  return nullptr;
}

template <typename K, typename V> void HashMap<K, V>::rehash() {
#ifdef DEBUG
  std::cout << "Rehashing!" << std::endl;
#endif
  // todo: thread safe.
  // reseting nElements to 0 is not thread safe.
  nElements = 0;
  auto oldN = nBuckets;
  nBuckets = 2 * nBuckets;
  auto oldBuckets = buckets;
  buckets = new Cell *[nBuckets];
  for (auto i = 0; i < nBuckets; i++)
    buckets[i] = nullptr;
  for (auto i = 0; i < oldN; i++) {
    auto ptr = oldBuckets[i];
    while (ptr != nullptr) {
      auto oldPtr = ptr;
      ptr = oldPtr->next;
#ifdef DEBUG
      std::cout << "Reput " << oldPtr->key << " -> " << oldPtr->value
                << std::endl;
#endif
      put(oldPtr->key, oldPtr->value);
      delete oldPtr;
    }
  }
  delete[] oldBuckets;
}

#endif // MYHASHMAP_H
