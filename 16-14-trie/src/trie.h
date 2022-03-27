#ifndef TRIE_H
#define TRIE_H

#include <array>
#include <cstdlib>
#include <memory>
#include <string>

class Trie {
public:
  Trie();
  size_t size() const noexcept { return m_size; };
  bool contains(std::string const &word) const;
  bool add(std::string const &word);
  size_t addFile(std::string const &filename);

private:
  static int toIndex(char c);
  struct Node {
    std::array<std::unique_ptr<Node>, 26> ptrs;
    bool terminatng = false;
  };
  static bool addHelper(std::unique_ptr<Node> &no, std::string const &word,
                        size_t ind);
  std::unique_ptr<Node> m_data;
  size_t m_size;
};

#endif // TRIE_H
