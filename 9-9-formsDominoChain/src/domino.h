#ifndef DOMINO_H
#define DOMINO_H
#include <ios>

class Domino {
public:
  Domino(int left, int right);
  int getLeftPadDots() const;
  int getRightPadDots() const;
  Domino reverse() const;
  friend std::ostream &operator<<(std::ostream &os, Domino d);

private:
  int left, right;
};

std::ostream &operator<<(std::ostream &os, Domino d);

#endif // DOMINO_H
