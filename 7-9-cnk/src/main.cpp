#include "console.h"
#include <iomanip>
#include <iostream>
using namespace std;

typedef unsigned long long u64;

u64 combinations(u64 n, u64 k);

int main() {
  for (u64 i = 0; i < 10; i++) {
    for (int j = 0; j <= i; j++)
      cout << setw(5) << combinations(i, j);
    cout << endl;
  }
  return 0;
}

u64 combinations(u64 n, u64 k) {
  if (k > n)
    throw k;
  else if (n == 0)
    return 1;
  else if (k == 0 || k == n) // base case
    return 1;
  else
    return combinations(n - 1, k - 1) + combinations(n - 1, k);
}
