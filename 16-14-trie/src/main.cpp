#include "console.h"
#include "trie.h"
#include <cassert>
#include <iostream>

using namespace std;

int main() {
  Trie trie;
  assert(trie.size() == 0);
  assert(!trie.contains("hello"));
  trie.add("hello");
  assert(trie.size() == 1);
  assert(trie.contains("hello"));
  auto n_added = trie.addFile("EnglishWords.txt");
  assert(trie.size() == n_added + 1);
  assert(trie.contains("hello"));
  assert(trie.contains("world"));
  cout << "All Test Passed!" << endl;
  return 0;
}
