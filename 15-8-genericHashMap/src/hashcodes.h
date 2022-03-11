#ifndef HASHCODES_H
#define HASHCODES_H

#include <string>

#include "hashinit.h"

int hashcode(std::string const &str) noexcept;
inline constexpr int hashcode(int x) noexcept;
inline constexpr int hashcode(short x) noexcept;
inline constexpr int hashcode(long x) noexcept;
inline constexpr int hashcode(long long x) noexcept;
inline constexpr int hashcode(char x) noexcept;

int hashcode(std::string const &str) noexcept {
  unsigned hash = HASH_SEED;
  for (auto c : str)
    hash = HASH_MULTIPLIER * hash + c;
  return static_cast<int>(hash & HASH_MASK);
}

inline constexpr int hashcode(int x) noexcept { return x & HASH_MASK; };
inline constexpr int hashcode(short x) noexcept {
  return hashcode(static_cast<int>(x));
};
inline constexpr int hashcode(char x) noexcept {
  return hashcode(static_cast<int>(x));
};
inline constexpr int hashcode(long x) noexcept {
  return hashcode(static_cast<int>(x)) + hashcode(static_cast<int>(x >> 32));
};
inline constexpr int hashcode(long long x) noexcept {
  return hashcode(static_cast<int>(x)) + hashcode(static_cast<int>(x >> 32));
};
#endif // HASHCODES_H
