#include "console.h"
#include "simpio.h"
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
  Stack<int> stack;
  cout << "Enter a list of integers, ending with 0:" << endl;
  int n;
  while (true) {
    n = getInteger("? ");
    if (n != 0)
      stack.push(n);
    else
      break;
  }
  cout << "Those integers in reverse order are:" << endl;
  while (!stack.isEmpty())
    cout << "  " << stack.pop() << endl;
  return 0;
}
