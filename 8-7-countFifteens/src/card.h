#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

typedef uint8_t u8;

class Card {
public:
  enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
  static const u8 ACE = 1, JACK = 11, QUEEN = 12, KING = 13;
  Card();
  Card(string const &str);
  Card(u8 rank, Suit suit);
  void set(u8 rank, Suit suit);
  void set(string const &str);
  friend ostream &operator<<(ostream &os, const Card &card);
  string toString() const;
  u8 getRank() const;
  Suit getSuit() const;

private:
  static const u8 UNINITIALIZED = 127;
  bool isSet() const;
  u8 rank = UNINITIALIZED;
  Suit suit;
  Suit parseSuit(char c);
  void validate() const;
};

Card::Suit operator++(Card::Suit &suit, int);
ostream &operator<<(ostream &os, Card::Suit suit);

#endif // CARD_H
