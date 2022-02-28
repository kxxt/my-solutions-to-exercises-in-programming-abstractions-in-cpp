#include "console.h"
#include "vector.h"
#include <iostream>
using namespace std;

int findDuplicate(Vector<int> const &vec);

int main() {
  cout << findDuplicate(Vector<int>{1, 2, 3, 4, 5, 3}) << endl;
  cout << findDuplicate(Vector<int>{1, 5, 6, 3, 2, 4, 9, 7, 8, 4}) << endl;
  return 0;
}

int findDuplicate(Vector<int> const &vec) {
  int N = vec.size();
  double sum = 0;
  for (auto &&v : vec)
    sum += v;
  double avg = sum / N;
  for (int i = 1; i < N; i++) {
    // the expected delta assuming the duplicate item is i.
    auto &&expected = double(N) / 2 - 0.5 + double(i) / N;
    auto delta = abs(avg - expected);
    if (delta < numeric_limits<double>::epsilon())
      return i;
  }
  return -1;
}
