#include "region.h"
#include <iostream>

using namespace std;

Region::Region(unsigned height, unsigned width) {
  grid = Grid<bool>(height, width);
}

Region::Region(std::initializer_list<std::initializer_list<bool>> init) {
  grid = Grid<bool>(init);
}

void Region::printRegion() {
  for (int i = 0; i < grid.height(); i++) {
    for (int j = 0; j < grid.width(); j++) {
      cout << (grid[i][j] ? '*' : ' ');
    }
    cout << endl;
  }
}

const int deltas[] = {-1, 0, 1};

void Region::fill(int r, int c) {
  if (!grid.inBounds(r, c) || grid[r][c])
    return;
  grid[r][c] = true;
  for (auto d : deltas) {
    int nr = r + d;
    int nc = c + d;
    fill(nr, c);
    fill(r, nc);
  }
}
