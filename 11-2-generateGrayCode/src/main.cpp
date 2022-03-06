#include "console.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<string> generateGrayCode(int nBits);

void generateGrayCodeHelper(int nBits, const string &prefix, bool reversed,
                            vector<string> &ans);

void printGrayCodes(vector<string> codes) {
  for_each(codes.begin(), codes.end(),
           [](auto const &code) { cout << code << endl; });
}

int main() {
  auto ans = generateGrayCode(3);
  printGrayCodes(ans);
  return 0;
}

vector<string> generateGrayCode(int nBits) {
  vector<string> ans;
  generateGrayCodeHelper(nBits, "", false, ans);
  return ans;
}

void generateGrayCodeHelper(int nBits, const string &prefix, bool reversed,
                            vector<string> &ans) {
  if (nBits == 0) {
    ans.push_back(prefix);
    return;
  }
  if (!reversed) {
    generateGrayCodeHelper(nBits - 1, prefix + '0', false, ans);
    generateGrayCodeHelper(nBits - 1, prefix + '1', true, ans);
  } else {
    generateGrayCodeHelper(nBits - 1, prefix + '1', false, ans);
    generateGrayCodeHelper(nBits - 1, prefix + '0', true, ans);
  }
}
