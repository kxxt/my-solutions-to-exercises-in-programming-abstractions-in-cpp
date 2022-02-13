#include "domino.h"

#include <sstream>

using namespace std;

Domino::Domino() { left = right = 0; }

Domino::Domino(size_t left, size_t right) {
  this->left = left;
  this->right = right;
}

string Domino::toString() {
  ostringstream os;
  os << this;
  return os.str();
}

size_t Domino::getLeftDots() const { return left; }

size_t Domino::getRightDots() const { return right; }

ostream &operator<<(ostream &os, Domino const &d) {
  return os << "Left: " << d.left << ", Right: " << d.right;
}
