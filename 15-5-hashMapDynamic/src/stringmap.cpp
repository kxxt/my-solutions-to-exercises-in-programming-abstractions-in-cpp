#include "stringmap.h"
#include "iostream"
using namespace std;

int hashcode(string const &str) noexcept {
  unsigned hash = HASH_SEED;
  for (auto c : str)
    hash = HASH_MULTIPLIER * hash + c;
  return static_cast<int>(hash & HASH_MASK);
}

StringMap::StringMap() {
  buckets = new Cell *[nBuckets];
  for (auto i = 0; i < nBuckets; i++)
    buckets[i] = nullptr;
}

StringMap::~StringMap() {
  for (auto i = 0; i < nBuckets; i++) {
    auto ptr = buckets[i];
    while (ptr != nullptr) {
      auto old = ptr;
      ptr = old->next;
      delete old;
    }
  }
}

optional<string> StringMap::get(const string &key) const noexcept {
  int bucketId = hashcode(key) % nBuckets;
  if (auto ptr = findCell(bucketId, key))
    return ptr->value;
  return optional<string>();
}

void StringMap::put(const string &key, string const &value) {
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
  cout << "Putting " << key << " -> " << value << endl;
#endif
  if (double(nElements) / nBuckets > REHASH_THRESHOLD)
    rehash();
}

StringMap::Cell *StringMap::findCell(int bucketId,
                                     const string &key) const noexcept {
  for (auto ptr = buckets[bucketId]; ptr != nullptr; ptr = ptr->next)
    if (ptr->key == key)
      return ptr;
  return nullptr;
}

void StringMap::rehash() {
#ifdef DEBUG
  cout << "Rehashing!" << endl;
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
      cout << "Reput " << oldPtr->key << " -> " << oldPtr->value << endl;
#endif
      put(oldPtr->key, oldPtr->value);
      delete oldPtr;
    }
  }
  delete[] oldBuckets;
}
