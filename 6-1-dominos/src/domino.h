#ifndef DOMINO_H
#define DOMINO_H

#include <string>

using namespace std;

class Domino {
public:
  Domino();
  Domino(size_t left, size_t right);
  string toString();
  size_t getLeftDots() const;
  size_t getRightDots() const;
  friend ostream &operator<<(ostream &os, Domino const &d);

private:
  size_t left, right;
};

#endif // DOMINO_H
