#include "console.h"
#include "grid.h"
#include <iostream>
using namespace std;

void fillGrid(Grid<int> &grid, Vector<int> const &values);

int main() {
  Grid<int> matrix(3, 3);
  Vector<int> values;
  values += 1, 2, 3;
  values += 4, 5, 6;
  values += 7, 8, 9;
  fillGrid(matrix, values);
  cout << matrix << endl;
  return 0;
}

void fillGrid(Grid<int> &grid, Vector<int> const &values) {
  int row = 0, col = 0;
  for (auto v : values) {
    grid[row][col++] = v;
    if (col == grid.width()) {
      col = 0;
      row++;
    }
  }
}
