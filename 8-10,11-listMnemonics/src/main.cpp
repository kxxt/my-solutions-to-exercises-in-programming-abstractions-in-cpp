#include "console.h"
#include "lexicon.h"
#include "strlib.h"
#include "vector.h"
#include <iostream>
using namespace std;

void listMnemonics(string const &num);
void listWordMnemonics(string const &num, Lexicon const &lex);
void getMnemonics(string const &num, Vector<string> &result,
                  function<bool(const string &)> predicat);
void getMnemoicsHelper(string const &num, Vector<string> &result,
                       string const &value, int cur,
                       function<bool(const string &)> predicate);

int main() {
  listMnemonics("723");
  listMnemonics("2");
  Lexicon lex("EnglishWords.txt");
  listWordMnemonics("723", lex);
  listWordMnemonics("2", lex);
  return 0;
}

void prettyPrintVector(Vector<string> const &vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
    if (i % 12 == 11)
      cout << endl;
  }
  if (vec.size() % 12 != 0)
    cout << endl;
}

void listWordMnemonics(string const &num, Lexicon const &lex) {
  Vector<string> result;
  getMnemonics(num, result, [&](const string &str) {
    return lex.contains(toLowerCase(str));
  });
  prettyPrintVector(result);
}

void listMnemonics(string const &num) {
  Vector<string> result;
  getMnemonics(num, result, [](const string &) { return true; });
  prettyPrintVector(result);
}

void getMnemonics(string const &num, Vector<string> &result,
                  function<bool(const string &)> predicate) {
  getMnemoicsHelper(num, result, "", 0, predicate);
}

string const numPadAlphas[]{"",    "",    "ABC",  "DEF", "GHI",
                            "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void getMnemoicsHelper(string const &num, Vector<string> &result,
                       string const &value, int cur,
                       function<bool(const string &)> predicate) {
  if (cur == num.length()) {
    if (predicate(value))
      result.add(value);
    return;
  }
  for (auto c : numPadAlphas[num[cur] - '0'])
    getMnemoicsHelper(num, result, value + c, cur + 1, predicate);
}
