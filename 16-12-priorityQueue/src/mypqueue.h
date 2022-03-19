#ifndef MYPQUEUE_H
#define MYPQUEUE_H

#include <cassert>
#include <iomanip>
#include <ios>
#include <vector>

template <typename T, typename P> class PriorityQueue {
public:
  size_t size() const noexcept { return m_data.size(); }
  size_t capicity() const noexcept { return m_data.capacity(); }
  void enqueue(T element, P priority);
  T dequeue();
  T peek() const;
  PriorityQueue() = default;
  template <typename TX, typename PX>
  friend std::ostream &operator<<(std::ostream &os,
                                  PriorityQueue<TX, PX> const &q);

private:
  struct Item {
    T value;
    P priority;
    Item(T value, P priority) : value(value), priority(priority) {}
  };
  static constexpr int parent(int n) noexcept { return (n - 1) / 2; }
  static constexpr int leftChild(int n) noexcept { return 2 * n + 1; }
  static constexpr int rightChild(int n) noexcept { return 2 * n + 2; }
  void swapUp(int id);
  void swapDown(int id);
  std::vector<Item> m_data;
};

template <typename T, typename P> T PriorityQueue<T, P>::peek() const {
  assert(!m_data.empty());
  return m_data[0].value;
}

template <typename T, typename P>
void PriorityQueue<T, P>::enqueue(T value, P priority) {
  m_data.emplace_back(value, priority);
  swapUp(m_data.size() - 1);
}

template <typename T, typename P> void PriorityQueue<T, P>::swapUp(int id) {
  auto par = parent(id);
  if (m_data[id].priority >= m_data[par].priority)
    return;
  std::swap(m_data[id], m_data[par]);
  swapUp(par);
}

template <typename T, typename P> T PriorityQueue<T, P>::dequeue() {
  assert(!m_data.empty());
  auto ret = m_data.begin()->value;
  *m_data.begin() = *--m_data.end();
  m_data.pop_back();
  swapDown(0);
  return ret;
}

template <typename T, typename P> void PriorityQueue<T, P>::swapDown(int id) {
  auto l = leftChild(id);
  auto r = rightChild(id);
  if (l >= m_data.size()) // l out of bound
    return;
  if (r >= m_data.size() &&
      m_data[id].priority > m_data[l].priority) { // r out of bound
    std::swap(m_data[l], m_data[id]);
    // we don't need to swap down here.
    return;
  }
  if (m_data[id].priority < m_data[l].priority &&
      m_data[id].priority < m_data[r].priority) // already minimum
    return;
  if (m_data[l].priority < m_data[r].priority) {
    std::swap(m_data[l], m_data[id]);
    swapDown(l);
  } else {
    std::swap(m_data[r], m_data[id]);
    swapDown(r);
  }
}

template <typename T, typename P>
std::ostream &operator<<(std::ostream &os, PriorityQueue<T, P> const &q) {
  int cnt = 1, r = 1;
  for (int i = 0; i < q.size(); i++) {
    if (r == 0) {
      cnt *= 2;
      r = cnt;
      os << std::endl;
    }
    os << std::setw(4) << q.m_data[i].priority;
    --r;
  }
  return os;
}

#endif // MYPQUEUE_H
