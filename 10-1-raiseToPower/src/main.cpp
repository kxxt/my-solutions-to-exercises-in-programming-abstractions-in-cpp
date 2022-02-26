#include "console.h"
#include <iostream>

#define DEBUG

using namespace std;

double raiseToPower(double x, int n);

#ifdef DEBUG
static int counter = 0;
#endif

int main() {
  cout << fixed << raiseToPower(2.0, 32) << endl;
#ifdef DEBUG
  cout << counter << " method calls in total!" << endl;
#endif
  return 0;
}

double raiseToPower(double x, int n) {
#ifdef DEBUG
  counter++;
#endif
  if (n < 0)
    throw "not implemented";
  if (n == 0)
    return 1;
  if (n == 1) // Optional optimization for reducing method calls
    return x;
  double ans = raiseToPower(x, n / 2);
  if (n % 2 == 0) {
    return ans * ans;
  } else {
    return x * ans * ans;
  }
}
