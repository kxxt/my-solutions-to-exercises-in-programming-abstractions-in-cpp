#include "domino.h"
#include "iostream"

static inline bool checkDominoDots(int n) { return n > 0 && n < 7; }

Domino::Domino(int left, int right) {
  if (!checkDominoDots(left) || !checkDominoDots(right))
    throw "Value out of range!";
  this->left = left;
  this->right = right;
}

int Domino::getLeftPadDots() const { return left; }
int Domino::getRightPadDots() const { return right; }
Domino Domino::reverse() const { return Domino(right, left); }

std::ostream &operator<<(std::ostream &os, Domino d) {
  return os << "(" << d.left << ", " << d.right << ")";
}
