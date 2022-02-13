#include "card.h"
#include "console.h"
#include "vector.h"
#include <iostream>

using namespace std;

int countFifteens(Vector<Card> const &cards);
int countFifteensHelper(Vector<Card> const &cards, int value, int cur);

int main() {
  cout << countFifteens(Vector<Card>{Card("AD"), Card("5C"), Card("10S"),
                                     Card("4H"), Card("9C")})
       << endl;
  cout << countFifteens(Vector<Card>{Card("5C"), Card("5D"), Card("5H"),
                                     Card("5S"), Card("JC")})
       << endl;
  return 0;
}

int countFifteens(Vector<Card> const &cards) {
  return countFifteensHelper(cards, 15, 0);
}

inline int getCardValue(int rank) { return rank > 10 ? 10 : rank; }

int countFifteensHelper(Vector<Card> const &cards, int value, int cur) {
  if (cur == cards.size()) {
    return value == 0;
  }
  return countFifteensHelper(cards, value, cur + 1) +
         countFifteensHelper(cards, value - getCardValue(cards[cur].getRank()),
                             cur + 1);
}
