#ifndef BST_H
#define BST_H

#include <memory>

template <typename T> class BalancedBinarySearchTree {
public:
  size_t size() const noexcept { return m_size; };
  inline void insert(T const &key);
  inline bool contains(T const &key) const noexcept;
  inline void clear();
  BalancedBinarySearchTree() = default;
  // disable copying
  BalancedBinarySearchTree(BalancedBinarySearchTree const &) = delete;
  BalancedBinarySearchTree &
  operator=(BalancedBinarySearchTree const &) = delete;
  // enable moving
  BalancedBinarySearchTree(BalancedBinarySearchTree &&);
  BalancedBinarySearchTree &operator=(BalancedBinarySearchTree &&);

private:
  // Node structure
  struct Node {
    T key;
    char balanceFactor;
    std::unique_ptr<Node> left, right;
  };
  // private methods
  bool containsHelper(std::unique_ptr<Node> const &no,
                      T const &key) const noexcept;
  char insertAVL(std::unique_ptr<Node> &no, T const &key);
  void rotateLeft(std::unique_ptr<Node> &no);
  void rotateRight(std::unique_ptr<Node> &no);
  void fixLeftImbalance(std::unique_ptr<Node> &no);
  void fixRightImbalance(std::unique_ptr<Node> &no);
  // member variables
  size_t m_size = 0;
  std::unique_ptr<Node> m_root = nullptr;
};

template <typename T>
inline bool BalancedBinarySearchTree<T>::contains(T const &key) const noexcept {
  return containsHelper(m_root, key);
}

template <typename T>
inline bool
BalancedBinarySearchTree<T>::containsHelper(std::unique_ptr<Node> const &no,
                                            T const &key) const noexcept {
  if (no == nullptr)
    return false;
  if (no->key == key)
    return true;
  if (no->key > key)
    return containsHelper(no->left, key);
  else
    return containsHelper(no->right, key);
}

template <typename T> void BalancedBinarySearchTree<T>::insert(T const &key) {
  insertAVL(m_root, key);
}

// Returns: the change of depth.
template <typename T>
char BalancedBinarySearchTree<T>::insertAVL(std::unique_ptr<Node> &no,
                                            T const &key) {
  if (no == nullptr) {
    ++m_size;
    no = std::make_unique<Node>();
    no->key = key;
    no->balanceFactor = 0;
    no->left = nullptr;
    no->right = nullptr;
    return 1;
  }
  if (no->key == key)
    return 0;
  if (no->key < key) {
    // insert to right sub-tree
    if (auto delta = insertAVL(no->right, key); delta == 0)
      return 0;
    switch (no->balanceFactor) {
    case 0:
      no->balanceFactor = 1;
      return 1;
    case -1:
      no->balanceFactor = 0;
      return 0;
    case 1:
      fixRightImbalance(no);
      return 0;
    }
  } else {
    // insert to left sub-tree
    if (auto delta = insertAVL(no->left, key); delta == 0)
      return 0;
    switch (no->balanceFactor) {
    case 0:
      no->balanceFactor = -1;
      return 1;
    case 1:
      no->balanceFactor = 0;
      return 0;
    case -1:
      fixLeftImbalance(no);
      return 0;
    }
  }
  throw "This place is thought to be unreachable!";
}

template <typename T> void BalancedBinarySearchTree<T>::clear() {
  m_root = nullptr;
  m_size = 0;
}

template <typename T>
void BalancedBinarySearchTree<T>::fixLeftImbalance(std::unique_ptr<Node> &no) {
  auto &child = no->left;
  if (child->balanceFactor != no->balanceFactor) {
    // double rotation.
    auto oldBF = child->right->balanceFactor;
    rotateLeft(no->left);
    rotateRight(no);
    no->balanceFactor = 0;
    switch (oldBF) {
    case -1:
      no->left->balanceFactor = 0;
      no->right->balanceFactor = 1;
      return;
    case 0:
      no->left->balanceFactor = no->right->balanceFactor = 0;
      return;
    case 1:
      no->left->balanceFactor = -1;
      no->right->balanceFactor = 0;
      return;
    }
  }
  // single rotation.
  rotateRight(no);
  no->right->balanceFactor = no->balanceFactor = 0;
}

template <typename T>
void BalancedBinarySearchTree<T>::fixRightImbalance(std::unique_ptr<Node> &no) {
  auto &child = no->right;
  if (child->balanceFactor != no->balanceFactor) {
    // double rotation.
    auto oldBF = child->left->balanceFactor;
    rotateRight(no->right);
    rotateLeft(no);
    no->balanceFactor = 0;
    switch (oldBF) {
    case -1:
      no->left->balanceFactor = 0;
      no->right->balanceFactor = 1;
      return;
    case 0:
      no->left->balanceFactor = no->right->balanceFactor = 0;
      return;
    case 1:
      no->left->balanceFactor = -1;
      no->right->balanceFactor = 0;
      return;
    }
  }
  // single rotation.
  rotateLeft(no);
  no->left->balanceFactor = no->balanceFactor = 0;
}

template <typename T>
void BalancedBinarySearchTree<T>::rotateRight(std::unique_ptr<Node> &no) {
  auto child = std::move(no->left);
  no->left = std::move(child->right);
  child->right = std::move(no);
  no = std::move(child);
}

template <typename T>
void BalancedBinarySearchTree<T>::rotateLeft(std::unique_ptr<Node> &no) {
  auto child = std::move(no->right);
  no->right = std::move(child->left);
  child->left = std::move(no);
  no = std::move(child);
}

template <typename T>
BalancedBinarySearchTree<T>::BalancedBinarySearchTree(
    BalancedBinarySearchTree<T> &&src) {
  m_root = std::move(src.m_root);
  m_size = src.m_size;
  src.m_size = 0;
}

template <typename T>
BalancedBinarySearchTree<T> &
BalancedBinarySearchTree<T>::operator=(BalancedBinarySearchTree<T> &&src) {
  m_root = std::move(src.m_root);
  m_size = src.m_size;
  src.m_size = 0;
}

#endif // BST_H
