#include "console.h"
#include "random.h"
#include "vector.h"
#include <algorithm>
#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

Vector<int> &insertionSort(Vector<int> &vec);

void printTableHeader();
void printTableColumn(int N);
int main() {
  Vector<int> ns{10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};
  printTableHeader();
  for (auto n : ns)
    printTableColumn(n);
  return 0;
}

void printTableHeader() {
  cout << "     N    |   Time (msec)" << endl
       << "----------------------------" << endl;
}

void printTableColumn(int N) {
  Vector<int> vec;
  auto cur = N;
  while (cur-- > 0)
    vec += randomInteger(0, INT_MAX);
  double start = double(clock()) / CLOCKS_PER_SEC;
  insertionSort(vec);
  double elapsed = double(clock()) / CLOCKS_PER_SEC - start;
  cout << setw(8) << right << N << "  |  " << setw(9) << right
       << setprecision(5) << fixed << elapsed << endl;
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
