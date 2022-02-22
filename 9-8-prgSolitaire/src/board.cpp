#include "board.h"
#include "direction.h"
#include "point.h"
#include <iostream>
#include <unistd.h>

const int Board::BOARD_SIZE = 7;
const Point Board::CENTER(3, 3);

Board::Board() {
  grid = Grid<bool>{
      {0, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 0, 0},
      {0, 0, 1, 1, 1, 0, 0},
  };
  pegCount = 32;
}

bool Board::inBounds(int x, int y) const {
  if (x <= 1 && y <= 1)
    return false;
  else if (x > 4 && y <= 1)
    return false;
  else if (x > 4 && y > 4)
    return false;
  else if (x <= 1 && y > 4)
    return false;
  return 0 <= x && x < Board::BOARD_SIZE && 0 <= y && y < Board::BOARD_SIZE;
}

inline bool Board::inBounds(Point p) const {
  return inBounds(p.getX(), p.getY());
}

inline bool Board::get(int x, int y) const {
  if (!inBounds(x, y))
    throw "Out of bound!";
  return grid[y][x];
}

inline bool &Board::at(int x, int y) {
  if (!inBounds(x, y))
    throw "Out of bound!";
  return grid[y][x];
}

inline bool &Board::at(Point p) { return at(p.getX(), p.getY()); }
inline bool Board::get(Point p) const { return get(p.getX(), p.getY()); }

Point getAdjcentPoint(int x, int y, Direction dir) {
  switch (dir) {
  case NORTH:
    return Point(x, y - 1);
  case SOUTH:
    return Point(x, y + 1);
  case WEST:
    return Point(x - 1, y);
  case EAST:
    return Point(x + 1, y);
  default:
    throw "ERROR: Invalid direction!";
  }
}

bool Board::canPegJump(int x, int y, Direction dir) const {
  // Check starting point
  if (!inBounds(x, y))
    return false;
  if (!get(x, y)) // There should be a peg
    return false;
  // Check the intermediate point
  auto p = getAdjcentPoint(x, y, dir);
  if (!inBounds(p))
    return false;
  if (get(p) != true) // There should be a peg
    return false;
  // Check the destination point
  p = getAdjcentPoint(p.getX(), p.getY(), dir);
  if (!inBounds(p))
    return false;
  if (get(p) != false) // The destination should be empty
    return false;
  return true;
}

void Board::jumpPeg(int x, int y, Direction dir) {
  --pegCount;
  at(x, y) = false;
  auto p = getAdjcentPoint(x, y, dir);
  at(p) = false;
  p = getAdjcentPoint(p.getX(), p.getY(), dir);
  at(p) = true;
}

inline void Board::jumpPeg(Point p, Direction dir) {
  jumpPeg(p.getX(), p.getY(), dir);
}

inline void Board::unjumpPeg(Point p, Direction dir) {
  unjumpPeg(p.getX(), p.getY(), dir);
}

void Board::unjumpPeg(int x, int y, Direction dir) {
  ++pegCount;
  at(x, y) = true;
  auto p = getAdjcentPoint(x, y, dir);
  at(p) = true;
  p = getAdjcentPoint(p.getX(), p.getY(), dir);
  at(p) = false;
}

void Board::display() const {
  using namespace std;
  for (int y = 0; y < grid.height(); y++) {
    for (int x = 0; x < grid.width(); x++) {
      if (inBounds(x, y))
        cout << (grid[y][x] ? 'o' : 'x');
      else
        cout << " ";
    }
    cout << endl;
  }
}

int Board::getPegCount() const { return pegCount; }
