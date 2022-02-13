#include "console.h"
#include <iostream>
using namespace std;

const int TEST_START = 1, TEST_END = 1000;

unsigned cannonball(unsigned height);
unsigned cannonballAlt(unsigned height);

int main() {
  for (int i = TEST_START; i <= TEST_END; i++) {
    if (cannonball(i) != cannonballAlt(i))
      throw i;
  }
  return 0;
}

unsigned cannonball(unsigned height) {
  if (height == 0)
    return 0;
  else
    return height * height + cannonball(height - 1);
}

unsigned cannonballAlt(unsigned height) {
  // 1 + 4 + 9 + ... + n^2
  // sum [n(n-1) + n]
  // n(n+1)(2n+1)/6
  return (unsigned long long)(height * (height + 1) * (2 * height + 1)) / 6;
}
