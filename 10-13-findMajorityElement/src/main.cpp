#include "console.h"
#include "vector.h"
#include <iostream>
using namespace std;

int findMajorityElement(Vector<int> const &vec);

// ref: https://www.geeksforgeeks.org/majority-element/
// using Moore’s Voting Algorithm

int main() {
  Vector<int> a{0, 2, 0, 22, 2, 2, 2, 3, 4, 5};
  Vector<int> b{0, 2, 0, 2, 2, 3, 2, 2, 2, 3, 4, 2};
  cout << findMajorityElement(a) << endl;
  cout << findMajorityElement(b) << endl;
  return 0;
}

int findMajorityElement(Vector<int> const &vec) {
  if (vec.size() == 0)
    return -1; // special case
  // first, find the candidate
  int index = 0, count = 1;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == vec[index])
      count++;
    else
      count--;
    if (count == 0) {
      // reset the index
      index = i;
      count = 1;
    }
  }
  int candidate = vec[index];
  count = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == candidate) {
      count++;
      if (count > vec.size() / 2)
        return candidate;
    }
  }
  return -1;
}
