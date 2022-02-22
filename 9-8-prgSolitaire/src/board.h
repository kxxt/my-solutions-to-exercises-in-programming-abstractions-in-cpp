#ifndef BOARD_H
#define BOARD_H

#include "direction.h"
#include "grid.h"
#include "point.h"

class Board {
public:
  static const int BOARD_SIZE;
  static const Point CENTER;
  Board();
  bool inBounds(int x, int y) const;
  bool inBounds(Point p) const;
  // before calling jump, please call canPegJump to check if you can jump at
  // that point.
  void jumpPeg(int x, int y, Direction dir);
  void jumpPeg(Point p, Direction dir);
  void unjumpPeg(Point p, Direction dir);
  void unjumpPeg(int x, int y, Direction dir);
  bool canPegJump(int x, int y, Direction dir) const;
  bool canPegJump(Point p, Direction dir) const;
  int getPegCount() const;
  void display() const;
  bool get(int x, int y) const;
  bool get(Point p) const;

private:
  bool &at(int x, int y);
  bool &at(Point p);
  int pegCount;
  Grid<bool> grid;
};

#endif // BOARD_H
