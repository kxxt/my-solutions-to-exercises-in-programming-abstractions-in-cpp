#include "card.h"
#include "console.h"
#include <iostream>

using namespace std;

int main() {
  for (auto suit = Card::Suit::CLUBS; suit <= Card::Suit::SPADES; suit++) {
    for (int rank = Card::ACE; rank <= Card::KING; rank++) {
      cout << " " << Card(rank, suit);
    }
    cout << endl;
  }
  return 0;
}
