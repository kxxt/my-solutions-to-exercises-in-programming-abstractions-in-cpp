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
  std::optional<string> get(string const &key) noexcept;
  void put(string const &key, string const &value);
  // Explicitly disable the generation of special member functions.
  StringMap(StringMap const &) = delete;
  StringMap &operator=(StringMap const &) = delete;
  StringMap(StringMap &&) = delete;
  StringMap &operator=(StringMap &&) = delete;
  ~StringMap();

private:
  static constexpr int INITIAL_BUCKET_COUNT = 13;
  // private structures
  struct Cell {
    string key;
    string value;
    Cell *next;
  };
  // private variables
  Cell **buckets;
  int nBuckets;
  // private functions
  Cell *findCell(int bucketId, string const &key) noexcept;
};

#endif // STRINGMAP_H
