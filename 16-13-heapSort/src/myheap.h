#ifndef MYHEAP_H
#define MYHEAP_H

#include <cassert>
#include <iomanip>
#include <ios>
#include <vector>

template <typename P> class Heap {
public:
  size_t size() const noexcept { return m_data.size(); }
  size_t capicity() const noexcept { return m_data.capacity(); }
  void enqueue(P priority);
  P dequeue();
  P peek() const;
  bool empty() const noexcept { return m_data.size() == 0; }
  Heap() = default;
  template <typename PX>
  friend std::ostream &operator<<(std::ostream &os, Heap<PX> const &q);

private:
  static constexpr int parent(int n) noexcept { return (n - 1) / 2; }
  static constexpr int leftChild(int n) noexcept { return 2 * n + 1; }
  static constexpr int rightChild(int n) noexcept { return 2 * n + 2; }
  void swapUp(int id);
  void swapDown(int id);
  std::vector<P> m_data;
};

template <typename P> P Heap<P>::peek() const {
  assert(!m_data.empty());
  return m_data[0];
}

template <typename P> void Heap<P>::enqueue(P priority) {
  m_data.push_back(priority);
  swapUp(m_data.size() - 1);
}

template <typename P> void Heap<P>::swapUp(int id) {
  auto par = parent(id);
  if (m_data[id] >= m_data[par])
    return;
  std::swap(m_data[id], m_data[par]);
  swapUp(par);
}

template <typename P> P Heap<P>::dequeue() {
  assert(!m_data.empty());
  auto ret = *m_data.begin();
  *m_data.begin() = *--m_data.end();
  m_data.pop_back();
  swapDown(0);
  return ret;
}

template <typename P> void Heap<P>::swapDown(int id) {
  auto l = leftChild(id);
  auto r = rightChild(id);
  if (l >= m_data.size()) // l out of bound
    return;
  if (r >= m_data.size() && m_data[id] > m_data[l]) { // r out of bound
    std::swap(m_data[l], m_data[id]);
    // we don't need to swap down here.
    return;
  }
  if (m_data[id] < m_data[l] && m_data[id] < m_data[r]) // already minimum
    return;
  if (m_data[l] < m_data[r]) {
    std::swap(m_data[l], m_data[id]);
    swapDown(l);
  } else {
    std::swap(m_data[r], m_data[id]);
    swapDown(r);
  }
}

template <typename P>
std::ostream &operator<<(std::ostream &os, Heap<P> const &q) {
  int cnt = 1, r = 1;
  for (int i = 0; i < q.size(); i++) {
    if (r == 0) {
      cnt *= 2;
      r = cnt;
      os << std::endl;
    }
    os << std::setw(4) << q.m_data[i];
    --r;
  }
  return os;
}

#endif // MYHEAP_H
