#include "console.h"
#include "stack.h"
#include <iostream>
using namespace std;

void roll(Stack<char> &stack, size_t n, size_t k);

int main() {
  Stack<char> base = {'A', 'B', 'C', 'D'};
  auto base1 = base, base2 = base, base3 = base;
  cout << base << endl;
  roll(base1, 4, 1);
  roll(base2, 3, 2);
  roll(base3, 2, 4);
  cout << base1 << endl << base2 << endl << base3 << endl;
  return 0;
}

void roll(Stack<char> &stack, size_t n, size_t k) {
  if (n > stack.size())
    error("roll: argument n out of range.");
  if (k > n)
    k %= n;
  if (k == n || k == 0)
    return;
  Stack<char> topk, remain;
  while (topk.size() < k)
    topk.push(stack.pop());
  while (remain.size() < n - k)
    remain.push(stack.pop());
  while (!topk.isEmpty())
    stack.push(topk.pop());
  while (!remain.isEmpty())
    stack.push(remain.pop());
}
