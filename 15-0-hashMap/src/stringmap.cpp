#include "stringmap.h"

using namespace std;

int hashcode(string const &str) noexcept {
  unsigned hash = HASH_SEED;
  for (auto c : str)
    hash = HASH_MULTIPLIER * hash + c;
  return static_cast<int>(hash & HASH_MASK);
}

StringMap::StringMap() {
  nBuckets = INITIAL_BUCKET_COUNT;
  buckets = new Cell *[nBuckets];
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

optional<string> StringMap::get(const string &key) noexcept {
  int bucketId = hashcode(key) % nBuckets;
  if (auto ptr = findCell(bucketId, key))
    return ptr->value;
  return optional<string>();
}

void StringMap::put(const string &key, string const &value) {
  int bucketId = hashcode(key) % nBuckets;
  auto ptr = findCell(bucketId, key);
  if (ptr == nullptr) {
    ptr = new Cell;
    ptr->key = key;
    // insert it before the first Cell in the bucket.
    ptr->next = buckets[bucketId];
    buckets[bucketId] = ptr;
  }
  ptr->value = value;
}

StringMap::Cell *StringMap::findCell(int bucketId, const string &key) noexcept {
  for (auto ptr = buckets[bucketId]; ptr != nullptr; ptr = ptr->next)
    if (ptr->key == key)
      return ptr;
  return nullptr;
}
