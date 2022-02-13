#include "console.h"
#include "domino.h"
#include <iostream>

using namespace std;

int main() {
  for (int i = 0; i <= 6; i++) {
    for (int j = i; j >= 0; j--) {
      Domino d(i, j);
      cout << d << endl;
    }
  }
  cout << "Hello, world!" << endl;
  return 0;
}
