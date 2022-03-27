#include "trie.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

Trie::Trie() {
  m_data = make_unique<Trie::Node>();
  m_size = 0;
}

int Trie::toIndex(char c) { return tolower(c) - 'a'; }

bool Trie::contains(string const &word) const {
  Trie::Node const *cur = m_data.get();
  for (auto it = word.begin(); it != word.end(); ++it) {
    if (cur == nullptr)
      return false;
    auto ind = toIndex(*it);
    assert(ind >= 0 && ind < 26);
    cur = cur->ptrs[ind].get();
  }
  if (cur == nullptr || !cur->terminatng)
    return false;
  return true;
}

bool Trie::add(const std::string &word) {
  if (addHelper(m_data, word, 0)) {
    ++m_size;
    return true;
  }
  return false;
}

size_t Trie::addFile(const std::string &filename) {
  ifstream ifs(filename);
  string line;
  size_t cnt = 0;
  while (getline(ifs, line)) {
    // deals with <CR>
    auto last = line.end() - 1;
    if (*last == '\r')
      line.erase(last);
    if (add(line))
      ++cnt;
  }
  return cnt;
}

bool Trie::addHelper(std::unique_ptr<Node> &no, const std::string &word,
                     size_t ind) {
  if (word.length() == ind) {
    if (no == nullptr) {
      no = make_unique<Node>();
      no->terminatng = true;
      return true;
    }
    if (!no->terminatng) {
      no->terminatng = true;
      return true;
    }
    return false;
  }
  if (no == nullptr)
    no = make_unique<Node>();
  return addHelper(no->ptrs[toIndex(word[ind])], word, ind + 1);
}
