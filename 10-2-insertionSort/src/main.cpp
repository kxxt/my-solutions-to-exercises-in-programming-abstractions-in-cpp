#include "console.h"
#include "vector.h"
#include <algorithm>
#include <iostream>
using namespace std;

Vector<int> &insertionSort(Vector<int> &vec);

int main() {
  Vector<int> a{56, 25, 37, 58, 95, 19, 73, 30};
  cout << insertionSort(a) << endl;
  return 0;
}

Vector<int> &insertionSort(Vector<int> &vec) {
  int nOrdered = 1;
  while (nOrdered < vec.size()) {
    int next = vec[nOrdered], idx = 0;
    while (idx < nOrdered && vec[idx] < next)
      ++idx;
    // idx points to the first element that is larger than next(or equals to
    // next)
    // swap the other elements to the right side
    for (int i = nOrdered; i > idx; i--)
      swap(vec[i], vec[i - 1]);
    vec[idx] = next;
    ++nOrdered;
  }
  return vec;
}
