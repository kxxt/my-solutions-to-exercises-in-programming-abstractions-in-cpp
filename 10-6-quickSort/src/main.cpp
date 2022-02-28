#include "console.h"
#include "vector.h"
#include <algorithm>
#include <iostream>
using namespace std;

void quickSort(Vector<int> &vec, int begin, int end);

int main() {
  Vector<int> a{78,  123,  23, 1,     13248, 34,     345,
                273, 2103, 34, -2314, 34,    343924, 24};
  cout << a << endl;
  quickSort(a, 0, a.size() - 1);
  cout << a << endl;
  return 0;
}

// The Quicksort algorithm, sorts elements in [begin, end], inclusive
void quickSort(Vector<int> &vec, int begin, int end) {
  if (begin >= end)
    return; // already sorted.
  // find the pivot index
  // Assume that pivotId is the idx of the middle element.
  int pivotId = begin + (end - begin) / 2;
  if (vec[begin] > vec[end]) {
    if (vec[pivotId] > vec[begin])
      pivotId = begin;
    else if (vec[pivotId] < vec[end])
      pivotId = end;
  } else {
    // vec[begin] < vec[end]
    if (vec[pivotId] < vec[begin])
      pivotId = begin;
    else if (vec[pivotId] > vec[end])
      pivotId = end;
  }
  // exchange the pivot with the first element of the vector.
  swap(vec[begin], vec[pivotId]);
  // partition
  int lh = begin + 1;
  int rh = end;
  int pivot =
      vec[begin]; // use begin instead of pivotId since we have swaped them.
  while (true) {
    while (lh < rh && vec[rh] >= pivot)
      --rh;
    while (lh < rh && vec[lh] < pivot)
      ++lh;
    if (lh == rh)
      break;
    swap(vec[lh], vec[rh]);
  }
  // lh==rh
  // try to swap the pivot with lh
  int boundary = lh;
  if (vec[lh] > pivot) {
    // in this case, do not swap.
    boundary = begin;
  } else {
    swap(vec[lh], vec[begin]);
  }
  //  cout << pivot << " " << boundary << " (" << begin << ", " << end << ") "
  //  << vec << endl;
  quickSort(vec, begin, boundary - 1);
  quickSort(vec, boundary + 1, end);
}
