#include "stringmap.h"
#include "iostream"
using namespace std;

int hashcode(string const &str) noexcept {
  unsigned hash = HASH_SEED;
  for (auto c : str)
    hash = HASH_MULTIPLIER * hash + c;
  return static_cast<int>(hash & HASH_MASK);
}

// todo: init memory to 0 for buckets.
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
  int bucketId = getBucketId(key);
  if (auto ptr = findCell(bucketId, key))
    return ptr->value;
  return optional<string>();
}

void StringMap::put(const string &key, string const &value) {
  int bucketId = getBucketId(key);
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
  cout << "[Bucket " << bucketId << "] Putting " << key << " -> " << value
       << endl;
#endif
  if (double(nElements) / nBuckets > REHASH_THRESHOLD)
    rehash();
}

void StringMap::putElement(const string &key, string const &value) {
  int bucketId = getBucketId(key);
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
}

void StringMap::add(const string &key, string const &value) {
  int bucketId = getBucketId(key);
  auto metaPtr = findPointerToCell(bucketId, key);
  if (metaPtr == nullptr) {
    put(key, value);
    return;
  }
#if DEBUG
  cout << "[Bucket " << bucketId << "] Adding " << key << " -> " << value
       << endl;
#endif
  auto ptr = *metaPtr;
  auto added = new Cell;
  added->value = value;
  added->key = key;
  added->next = ptr;
  *metaPtr = added;
  ++nElements;
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

StringMap::Cell **
StringMap::findPointerToCell(int bucketId, const string &key) const noexcept {
  auto ptr = buckets[bucketId];
  decltype(ptr) oldPtr;
  if (ptr == nullptr || ptr->key == key)
    return &buckets[bucketId];
  while (ptr != nullptr) {
    oldPtr = ptr;
    ptr = ptr->next;
    if (ptr != nullptr && ptr->key == key)
      return &(oldPtr->next);
  }
  return nullptr;
}

bool StringMap::remove(const string &key) {
  int bucketId = getBucketId(key);
  if (auto metaPtr = findPointerToCell(bucketId, key)) {
    auto ptr = *metaPtr; // ptr is not nullptr, guaranteed.
#ifdef DEBUG
    cout << "[Bucket " << bucketId << "] Removing " << ptr->key << " -> "
         << ptr->value << endl;
#endif
    *metaPtr = ptr->next;
    delete ptr;
    --nElements;
  }
  return false;
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
    auto &ptr = oldBuckets[i];
    while (ptr != nullptr) {
      // cout << "before: " << ptr << endl;
      rehashCascadingCells(ptr, ptr->key);
      // cout << "after: " << ptr << endl;
      //      if (ptr != nullptr) // ptr itself might be set to nullptr after
      //      call to
      //                          // rehashCascadingCells
      //        ptr = ptr->next;  // Note that ptr is a ref to pointer
    }
  }
  delete[] oldBuckets;
}

void StringMap::rehashCascadingCells(Cell *&nextPtr, string const &key) {
  if (nextPtr == nullptr || nextPtr->key != key)
    return;
  // cout << "rCC " << key << endl;
  rehashCascadingCells(nextPtr->next, key);
  add(nextPtr->key, nextPtr->value);
#ifdef DEBUG
  cout << "Readded " << nextPtr->key << " -> " << nextPtr->value << endl;
#endif
  auto next = nextPtr->next;
  delete nextPtr;
  nextPtr = next;
}
