#include "console.h"
#include "vector.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "strlib.h"

using namespace std;

void countValues(Vector<int> const &vec, Vector<int> &cnts);
void printHistogram(Vector<int> const& cnts);

int main() {
  Vector<int> vec{100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80};
  Vector<int> cnts;
  countValues(vec, cnts);
  printHistogram(cnts);
  return 0;
}

void countValues(Vector<int> const &vec, Vector<int> &cnts) {
  cnts.clear();
  for(int i=0;i<11;i++) cnts.add(0);
  // cnts.ensureCapacity(11);
  for (auto v : vec) {
    ++cnts[v / 10];
  }
}

void printHistogram(Vector<int> const& cnts){
    for(int i=0;i<10;i++)
        cout << setfill('0') << setw(2) << i*10 << "s: " << string(cnts[i], '*') << endl;
    cout << "100: " << string(cnts[10], '*') << endl;
}
