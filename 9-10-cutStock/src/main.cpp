#include "console.h"
#include "vector.h"
#include <climits>
#include <iostream>
using namespace std;

int cutStockHelper(Vector<int> const &requests, int stockLength,
                   Vector<bool> &selected, int &nRemaining, int curNum,
                   int lRemaining);
int cutStock(Vector<int> const &requests, int stockLength);

int main() {
  cout << cutStock(Vector<int>{4, 3, 4, 1, 7, 8}, 10) << endl;
  return 0;
}

int cutStock(Vector<int> const &requests, int stockLength) {
  Vector<bool> selected(requests.size());
  int nRemaining = selected.size();
  return cutStockHelper(requests, stockLength, selected, nRemaining, 0, 0);
}

int cutStockHelper(Vector<int> const &requests, int stockLength,
                   Vector<bool> &selected, int &nRemaining, int curNum,
                   int lRemaining) {
  if (nRemaining == 0)
    return curNum;
  int minNum = INT_MAX;
  for (int i = 0; i < requests.size(); i++) {
    auto &&request = requests[i];
    if (!selected[i]) {
      selected[i] = true;
      --nRemaining;
      if (lRemaining >= request) {
        minNum = min(minNum,
                     cutStockHelper(requests, stockLength, selected, nRemaining,
                                    curNum, lRemaining - request));
      } else {
        // throw the remaining part away.
        if (request > stockLength)
          throw "Pipe too long";
        minNum = min(minNum,
                     cutStockHelper(requests, stockLength, selected, nRemaining,
                                    curNum + 1, stockLength - request));
      }
      ++nRemaining;
      selected[i] = false;
    }
  }
  return minNum;
}
