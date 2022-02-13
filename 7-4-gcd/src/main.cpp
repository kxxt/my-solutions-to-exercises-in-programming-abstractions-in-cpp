#include "console.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
using namespace std;

const int TEST_BEGIN = 0, TEST_END = UINT_MAX;

int gcd(int a, int b);

int main() {
  cout << "Hello, world!" << endl;
  for (int a = TEST_BEGIN; a <= TEST_END; a++) {
    for (int b = TEST_BEGIN; b <= TEST_END; b++) {
      if (gcd(a, b) != __gcd(a, b))
        throw make_pair(a, b);
    }
  }
  return 0;
}

int gcd(int a, int b) {
  int r = a % b;
  if (r == 0)
    return b;
  else
    return gcd(b, r);
}
