#ifndef REGION_H
#define REGION_H

#include "grid.h"
#include <initializer_list>

class Region {
public:
  Region(unsigned height, unsigned width);
  Region(std::initializer_list<std::initializer_list<bool>> init);
  void printRegion();
  void fill(int r, int c);

private:
  Grid<bool> grid;
};

#endif // REGION_H
