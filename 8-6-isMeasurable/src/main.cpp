#include "console.h"
#include "simpio.h"
#include "vector.h"
#include <iostream>
using namespace std;

bool isMeasurableHelper(int target, Vector<int> const &weights, int cur);
bool isMeasurable(int target, Vector<int> const &weights);

int main() {
  Vector<int> weights{1, 3};
  cout << isMeasurable(2, weights) << endl;
  cout << isMeasurable(5, weights) << endl;
  return 0;
}

bool isMeasurable(int target, Vector<int> const &weights) {
  return isMeasurableHelper(target, weights, 0);
}

bool isMeasurableHelper(int target, Vector<int> const &weights, int cur) {
  if (cur == weights.size())
    return target == 0;
  return isMeasurableHelper(target + weights[cur], weights, cur + 1) ||
         isMeasurableHelper(target, weights, cur + 1) ||
         isMeasurableHelper(target - weights[cur], weights, cur + 1);
}
