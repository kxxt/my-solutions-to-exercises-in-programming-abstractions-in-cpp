#include "console.h"
#include "vector.h"
#include <iostream>
using namespace std;

const int MAX_BOUND = 10000;

void countingSort(Vector<int> &vec);

int main() {
  Vector<int> v{893, 2, 0, 1232, 2133, 23, 232, 88, 81, 121, 9887, 230, 9999};
  countingSort(v);
  cout << v << endl;
  return 0;
}

// for integers in range[0, 9999]
void countingSort(Vector<int> &vec) {
  Vector<int> count(MAX_BOUND);
  Vector<int> output(vec.size());
  // count numbers
  for (auto item : vec)
    count[item] += 1;
  // do a prefix sum
  for (int i = 1; i < MAX_BOUND; i++)
    count[i] += count[i - 1];
  // place numbers in position
  for (auto item : vec)
    output[--count[item]] = item;
  vec = output;
}
