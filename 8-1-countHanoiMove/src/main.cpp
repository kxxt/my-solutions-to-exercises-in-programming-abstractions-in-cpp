#include "console.h"
#include <iostream>
using namespace std;

unsigned countHanoiMove(unsigned n);

int main() {
  for (int i = 1; i < 11; i++)
    cout << countHanoiMove(i) << endl;
  return 0;
}

void countHanoiMoveHelper(unsigned &cnt, unsigned n, int source = 0,
                          int dest = 1, int tmp = 2);

unsigned countHanoiMove(unsigned n) {
  unsigned cnt = 0;
  countHanoiMoveHelper(cnt, n);
  return cnt;
}

void countHanoiMoveHelper(unsigned &cnt, unsigned n, int source, int dest,
                          int tmp) {
  if (n == 1)
    cnt++;
  else {
    countHanoiMoveHelper(cnt, n - 1, source, tmp, dest);
    countHanoiMoveHelper(cnt, 1, source, dest, tmp);
    countHanoiMoveHelper(cnt, n - 1, tmp, dest, source);
  }
}
