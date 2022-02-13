#include "card.h"

#include "strlib.h"

Card::Card() {}

void Card::set(u8 rank, Card::Suit suit) {
  this->rank = rank;
  this->suit = suit;
  validate();
}

void Card::set(const string &str) {
  if (isalpha(str[0])) {
    switch (str[0]) {
    case 'A':
      this->rank = 1;
      break;
    case 'J':
      this->rank = 11;
      break;
    case 'Q':
      this->rank = 12;
      break;
    case 'K':
      this->rank = 13;
      break;
    }
    assert(str.length() == 2);
  } else {
    this->rank = stringToInteger(str.substr(0, str.size() - 1));
  }
  this->suit = parseSuit(str[str.size() - 1]);
  validate();
}

Card::Suit Card::parseSuit(char c) {
  switch (c) {
  case 'C':
    return CLUBS;
  case 'D':
    return DIAMONDS;
  case 'H':
    return HEARTS;
  case 'S':
    return SPADES;
  default:
    error("Invalid suit character!");
  }
}

Card::Card(const string &str) { set(str); }

Card::Card(u8 rank, Card::Suit suit) { set(rank, suit); }

Card::Suit Card::getSuit() const { return suit; }
u8 Card::getRank() const { return rank; }

bool Card::isSet() const { return rank != Card::UNINITIALIZED; }

void Card::validate() const {
  if (1 <= rank && rank <= 13 && Suit::CLUBS <= suit && suit <= Suit::SPADES)
    return;
  error("Invalid card!");
}

Card::Suit operator++(Card::Suit &suit, int) {
  Card::Suit original = suit;
  suit = static_cast<Card::Suit>(suit + 1);
  return original;
}

ostream &operator<<(ostream &os, Card::Suit suit) {
  char c;
  switch (suit) {
  case Card::Suit::CLUBS:
    c = 'C';
    break;
  case Card::Suit::DIAMONDS:
    c = 'D';
    break;
  case Card::Suit::HEARTS:
    c = 'H';
    break;
  case Card::Suit::SPADES:
    c = 'S';
    break;
  default:
    error("Invalid suit!");
  }
  return os << c;
}

ostream &operator<<(ostream &os, Card const &card) {
  switch (card.rank) {
  case 1:
    os << 'A';
    break;
  case 11:
    os << 'J';
    break;
  case 12:
    os << 'Q';
    break;
  case 13:
    os << 'K';
    break;
  default:
    os << static_cast<int>(card.rank);
  }
  return os << card.suit;
}
