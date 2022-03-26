#include "console.h"
#include "myheap.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template <typename T> void heapSort(vector<T> &vec);

template <typename T> void printVector(vector<T> const &vec);

int main() {

  vector<int> v{82, 312, 321, 3, -123, 3743, 3, 23, -213, 213};
  printVector(v);
  heapSort(v);
  printVector(v);
  return 0;
}

template <typename T> void heapSort(vector<T> &vec) {
  Heap<T> heap;
  for (auto v : vec)
    heap.enqueue(v);
  for (auto &v : vec)
    v = heap.dequeue();
}

template <typename T> void printVector(vector<T> const &vec) {
  for (auto &&v : vec)
    cout << v << ' ';
  cout << endl;
}
