#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void removeComments(istream& is, ostream& os);

int main() {
  cout << "Hello World!" << endl;
  return 0;
}

string const beginComments = "/*";
string const endComments = "*/";
string const lineComment = "//";

// /*

/*
 *   //*
 * // */

/* // */

// inline bool isBegin(char prev, char ch) { return prev == '/' && ch == '*'; }
// inline bool isEnd(char prev, char ch) { return prev == '*' && ch == '/'; }
// inline bool isLine(char prev, char ch) { return prev == ch && ch == '/'; }

// void removeComments(istream& is, ostream& os) {
//  char ch, prev = -1;
//  if (!is.get(prev)) return;
//  bool inComments = false;
//  while (is.get(ch)) {
//    if (!inComments) {
//      if (isBegin(prev, ch)) {
//        inComments = true;
//      }
//      os << ch;
//    } else {
//    }
//    prev = ch;
//  }
//}

// /* ignore this kind of beginComments
// //* weird staff
/* // */  // sdasdf

int a;  //*//

enum LineType {
  Normal,     // no multiline comments
  Begin,      // with multiline comments' begin
  End,        // with multiline comments' end
  PassiveEnd  // it can be an end for a multiline comment, for example: // */
};

// returns: Line Type
LineType removeInlineComments(string& str) {
  while (true) {
    auto bpos = str.find(beginComments);
    auto epos = str.find(endComments);
    auto lpos = str.find(lineComment);
    if (bpos == string::npos &&
        epos == string::npos) {  // no block comments found
      if (lpos != string::npos) str.erase(lpos);
      return LineType::Normal;
    }
    if (bpos != string::npos && epos != string::npos) {
      // a complete block comment.
      str.erase(bpos, epos + 1 - bpos + 1);
      continue;
    }
    if (epos != string::npos) {
      // only endComments
      // */ //
      // // */
      // a /* what hell the fuck *//b ==> a /b
    }
    if (bpos != string::npos) {  // only beginComments
      // asd /*
      // asdasd /* //
      if (lpos == string::npos || lpos > bpos) {
        str.erase(bpos);
        return LineType::Begin;
      } else {  // //* // /*
        str.erase(lpos);
        return LineType::Normal;
      }
    }
  }
  return LineType::Normal;
}

void removeComments(istream& is, ostream& os) {
  string line;
  bool inComments = false;
  while (getline(is, line)) {
  }
}
