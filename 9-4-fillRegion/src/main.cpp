#include "console.h"
#include "region.h"
#include <iostream>
using namespace std;

int main() {
  Region r{{1, 1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1},
           {1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1},
           {1, 1, 1, 1, 1, 1, 1}};
  r.printRegion();
  r.fill(1, 1);
  r.printRegion();
  return 0;
}
