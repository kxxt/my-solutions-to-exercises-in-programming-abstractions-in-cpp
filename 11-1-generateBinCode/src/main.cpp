#include "console.h"
#include <iostream>
using namespace std;

void generateBinaryCodeHelper(const string &prefix, int nBits);

void generateBinaryCode(int nBits);
int main() {
  generateBinaryCode(3);
  return 0;
}

void generateBinaryCode(int nBits) { generateBinaryCodeHelper("", nBits); }

void generateBinaryCodeHelper(const string &prefix, int nBits) {
  if (nBits == 0) {
    cout << prefix << endl;
    return;
  }
  generateBinaryCodeHelper(prefix + '0', nBits - 1);
  generateBinaryCodeHelper(prefix + '1', nBits - 1);
}
