#include "bst.h"
#include "console.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  BalancedBinarySearchTree<int> bbst;
  assert(bbst.size() == 0);
  bbst.insert(10);
  assert(bbst.size() == 1);
  assert(bbst.contains(10));
  for (int i = 0; i < 10; i++)
    bbst.insert(i);
  assert(bbst.size() == 11);
  for (int i = 0; i < 10; i++)
    assert(bbst.contains(i));

  auto x = std::move(bbst);

  assert(bbst.size() == 0);
  assert(x.size() == 11);
  for (int i = 0; i < 10; i++)
    assert(x.contains(i));

  cout << "OK!" << endl;
  return 0;
}
