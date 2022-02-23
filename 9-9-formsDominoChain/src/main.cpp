#include "console.h"
#include "domino.h"
#include "vector.h"
#include <iostream>
#include <optional>
using namespace std;

#define DEBUG

bool formsDominoChainHelper(Vector<Domino> const &dominos,
                            Vector<bool> &selected, int &nSelected,
                            optional<Domino> prev = {});
bool formsDominoChain(Vector<Domino> const &dominos);

int main() {
  Vector<Domino> v1{
      Domino(1, 4),
      Domino(1, 6),
      Domino(2, 6),
      Domino(3, 4),
  };
  cout << formsDominoChain(v1) << endl;

  Vector<Domino> v2{Domino(1, 4), Domino(1, 6), Domino(2, 6), Domino(3, 4),
                    Domino(5, 6)};
  cout << formsDominoChain(v2) << endl;
  return 0;
}

bool formsDominoChain(Vector<Domino> const &dominos) {
  Vector<bool> selected(dominos.size());
  int nSelected{};
  return formsDominoChainHelper(dominos, selected, nSelected);
}

bool formsDominoChainHelper(Vector<Domino> const &dominos,
                            Vector<bool> &selected, int &nSelected,
                            optional<Domino> prev) {

  if (nSelected == dominos.size()) {
#ifdef DEBUG
    cout << prev.value() << endl;
#endif
    return true;
  }
  for (int i = 0; i < dominos.size(); i++) {
    if (!selected[i]) {
      selected[i] = true;
      ++nSelected;
      // Try to select i-th domino
      if (prev) { // Not the first one
        if (dominos[i].getLeftPadDots() == prev->getRightPadDots()) {
          if (formsDominoChainHelper(dominos, selected, nSelected,
                                     dominos[i])) {
#ifdef DEBUG
            cout << prev.value() << endl;
#endif
            return true;
          }
        }
        if (dominos[i].getRightPadDots() == prev->getRightPadDots()) {
          if (formsDominoChainHelper(dominos, selected, nSelected,
                                     dominos[i].reverse())) {
#ifdef DEBUG
            cout << prev.value() << endl;
#endif
            return true;
          }
        }
      } else {
        // the first one
        if (formsDominoChainHelper(dominos, selected, nSelected, dominos[i]))
          return true;
        if (formsDominoChainHelper(dominos, selected, nSelected,
                                   dominos[i].reverse()))
          return true;
      }
      selected[i] = false;
      --nSelected;
    }
  }
  return false;
}
