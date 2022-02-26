#include "console.h"
#include "random.h"
#include "vector.h"
#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

const int TEST_COUNT = 10;

int binarySearchHelper(Vector<int> const &vec, int val, int begin, int end,
                       int &count);
int binarySearch(Vector<int> const &vec, int val, int &count);
int linearSearch(Vector<int> const &vec, int val, int &count);
void printTableColumn(int N);
void printTable(Vector<int> const &ns);

int main() {
  printTable(Vector<int>{10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000});
  return 0;
}

void generateSortedVector(int N, Vector<int> &v) {
  v.clear();
  int prev = 0;
  while (N-- > 0) {
    prev = randomInteger(prev + 1, prev + 1000);
    v.add(prev);
  }
}

void printTable(Vector<int> const &ns) {
  cout << "    N    |  Linear  |  Binary  " << endl
       << "-------------------------------" << endl;
  for (auto n : ns)
    printTableColumn(n);
}

void printTableColumn(int N) {
  Vector<int> vec;
  int lTotal = 0, bTotal = 0;
  for (int i = 0; i < TEST_COUNT; i++) {
    generateSortedVector(N, vec);
    int idx = randomInteger(0, vec.size() - 1);
    if (idx != linearSearch(vec, vec[idx], lTotal))
      throw "ERROR in algorithm!";
    if (idx != binarySearch(vec, vec[idx], bTotal))
      throw "ERROR in algorithm!";
  }
  cout << fixed << right << setprecision(1) << setw(8) << N << " |" << setw(8)
       << lTotal / double(TEST_COUNT) << "  |" << setw(8)
       << bTotal / double(TEST_COUNT) << endl;
}

int linearSearch(Vector<int> const &vec, int val, int &count) {
  for (int i = 0; i < vec.size(); i++) {
    count++;
    if (vec[i] == val)
      return i;
  }
  return -1;
}

int binarySearch(Vector<int> const &vec, int val, int &count) {
  return binarySearchHelper(vec, val, 0, vec.size() - 1, count);
}

int binarySearchHelper(Vector<int> const &vec, int val, int begin, int end,
                       int &count) {
  int mid = begin + (end - begin) / 2;
  ++count;
  if (vec[mid] == val)
    return mid;
  ++count;
  if (begin >= end)
    return -1;
  ++count;
  if (vec[mid] > val)
    return binarySearchHelper(vec, val, begin, mid, count);
  else
    return binarySearchHelper(vec, val, mid + 1, end, count);
}
