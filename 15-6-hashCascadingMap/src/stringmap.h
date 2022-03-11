#ifndef STRINGMAP_H
#define STRINGMAP_H

#include <climits>
#include <optional>
#include <string>

constexpr int HASH_MASK = INT_MAX;
constexpr int HASH_SEED = 5381;
constexpr int HASH_MULTIPLIER = 33;

int hashcode(std::string const &str) noexcept;

class StringMap {
  using string = std::string;

public:
  StringMap();
  ~StringMap();
  // public member functions
  std::optional<string> get(string const &key) const noexcept;
  void put(string const &key, string const &value);
  void add(string const &key, string const &value);
  bool remove(string const &key);
  int size() const noexcept { return nElements; }
  // Explicitly disable the generation of special member functions.
  StringMap(StringMap const &) = delete;
  StringMap &operator=(StringMap const &) = delete;
  StringMap(StringMap &&) = delete;
  StringMap &operator=(StringMap &&) = delete;

private:
  static constexpr int INITIAL_BUCKET_COUNT = 13;
  static constexpr double REHASH_THRESHOLD = 0.7;
  // private structures
  struct Cell {
    string key;
    string value;
    Cell *next;
  };
  // private variables
  Cell **buckets;
  int nBuckets = INITIAL_BUCKET_COUNT;
  int nElements = 0;
  // private functions
  int getBucketId(string const &key) const noexcept {
    // This function will be automatically inlined
    return hashcode(key) % nBuckets;
  };
  Cell *findCell(int bucketId, string const &key) const noexcept;
  // This function returns a pointer to the pointer to the taret Cell.
  Cell **findPointerToCell(int bucketId, string const &key) const noexcept;
  void putElement(string const &key, string const &value);
  void rehash();
  void rehashCascadingCells(Cell *&nextPtr, string const &key);
};

#endif // STRINGMAP_H
