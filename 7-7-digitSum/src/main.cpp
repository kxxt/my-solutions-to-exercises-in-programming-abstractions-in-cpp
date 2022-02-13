#include "console.h"
#include <iostream>
using namespace std;

unsigned digitSum(unsigned n);
unsigned digitalRoot(unsigned n);

int main() {
  cout << digitSum(1729) << endl;
  cout << digitalRoot(1729) << endl;
  cout << digitalRoot(3) << endl;
  cout << digitalRoot(10234) << endl;

  return 0;
}

unsigned digitSum(unsigned n) {
  auto r = n % 10, d = n / 10;
  if (d == 0)
    return r;
  else
    return r + digitSum(d);
}

bool isSingleDigit(unsigned n) { return n / 10 == 0; }

unsigned digitalRoot(unsigned n) {
  while (!isSingleDigit(n)) {
    n = digitSum(n);
  }
  return n;
}
