#include "console.h"
#include <iostream>
using namespace std;

inline bool wildcardMatch(string const &filename, string const &pattern);
bool wildcardMatchHelper(string const &filename, string const &pattern,
                         int fpos, int ppos);
void testCase(string const &filename, string const &pattern, bool expected);

int main() {
  testCase("US.txt", "*.*", true);
  testCase("test", "*.*", false);
  testCase("test.h", "test.?", true);
  testCase("test.cpp", "test.?", false);
  testCase("x", "??*", false);
  testCase("yy", "??*", true);
  testCase("zzz", "??*", true);
  return 0;
}

void testCase(string const &filename, string const &pattern, bool expected) {
  if (expected != wildcardMatch(filename, pattern))
    throw "TEST FAILED! Use debugger to look into details.";
  cout << "wildcardMatch(\"" << filename << "\", \"" << pattern
       << "\") returns " << (expected ? "true" : "false") << endl;
}

inline bool wildcardMatch(string const &filename, string const &pattern) {
  return wildcardMatchHelper(filename, pattern, 0, 0);
}

bool wildcardMatchHelper(string const &filename, string const &pattern,
                         int fpos, int ppos) {
  if (ppos == pattern.size() && fpos >= filename.size())
    return true;
  auto ch = pattern[ppos];
  if (fpos >= filename.size() && ch != '*')
    return false;
  switch (ch) {
  case '?':
    return wildcardMatchHelper(filename, pattern, fpos + 1, ppos + 1);
  case '*':
    for (int i = filename.length() - fpos; i >= 0; i--)
      if (wildcardMatchHelper(filename, pattern, fpos + i, ppos + 1))
        return true;
    return false;
  default:
    if (ch == filename[fpos])
      return wildcardMatchHelper(filename, pattern, fpos + 1, ppos + 1);
    else
      return false;
  }
}
