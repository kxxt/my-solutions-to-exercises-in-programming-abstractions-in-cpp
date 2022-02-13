#include "console.h"
#include "vector.h"
#include <iostream>
using namespace std;

typedef uint32_t u32;

Vector<u32> findPrimes(u32 max);

int main() {
  auto result = findPrimes(1000);
  cout << result << endl;
  return 0;
}

Vector<u32> findPrimes(u32 max) {
  Vector<bool> isCrossed(max + 1, false);
  Vector<u32> result;
  for (u32 i = 2; i <= max; i++) {
    if (!isCrossed[i]) {
      for (int k = 2 * i; k <= max; k += i)
        isCrossed[k] = true;
    }
  }
  for (u32 i = 2; i <= max; i++) {
    if (!isCrossed[i])
      result.add(i);
  }
  return result;
}
