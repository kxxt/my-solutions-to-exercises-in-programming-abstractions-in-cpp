#include "console.h"
#include "fib.h"
#include <iomanip>
#include <iostream>
using namespace std;

const u64 TEST_BEGIN = 0, TEST_END = 30;

int main() {
  cout << "Validating program correctness..." << endl;
  for (int i = TEST_BEGIN; i <= TEST_END; i++) {
    u64 r1 = fib::rec::fib1(i);
    u64 r2 = fib::rec::fib2(i);
    u64 r3 = fib::itr::fib(i);
    if (!(r1 == r2 && r2 == r3))
      throw "FAILURE!";
  }
  cout << "Printing table..." << endl;
  cout << "   n\t  fib1\t  fib2" << endl;
  cout << "-------------------------" << endl;
  for (int i = 0; i < 13; i++) {
    cout << setw(8) << right << i << '\t' << setw(8) << fib::rec::countFib1(i)
         << '\t' << setw(8) << fib::rec::countFib2(i) << endl;
  }
  return 0;
}
