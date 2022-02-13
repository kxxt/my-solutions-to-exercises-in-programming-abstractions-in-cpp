#include "console.h"
#include "lexicon.h"
#include "strlib.h"
#include "vector.h"
#include <iostream>
using namespace std;

void getMnemonics(string const &num, Vector<string> &result,
                  function<bool(const string &)> predicat);
void getMnemoicsHelper(string const &num, Vector<string> &result,
                       string const &value, int cur,
                       function<bool(const string &)> predicate);
void getCompletions(string const &num, Lexicon const &lex,
                    Vector<string> &result);
void getCompletionsHelper(string const &prefix, Lexicon const &lex,
                          Vector<string> &result);
void listCompletions(string const &num, Lexicon const &lex);

int main() {
  Lexicon lex("EnglishWords.txt");
  listCompletions("72547", lex);
  return 0;
}

void prettyPrintVector(Vector<string> const &vec) {
  for (auto const &str : vec)
    cout << str << endl;
}

void listCompletions(string const &num, Lexicon const &lex) {
  Vector<string> result;
  getCompletions(num, lex, result);
  prettyPrintVector(result);
}

void getCompletions(string const &num, Lexicon const &lex,
                    Vector<string> &result) {
  Vector<string> prefixes;
  getMnemonics(num, prefixes,
               [&](const string &str) { return lex.containsPrefix(str); });
  for (auto const &prefix : prefixes) {
    getCompletionsHelper(prefix, lex, result);
  }
}

void getCompletionsHelper(string const &prefix, Lexicon const &lex,
                          Vector<string> &result) {
  if (!lex.containsPrefix(prefix))
    return;
  if (lex.contains(prefix))
    result.add(toLowerCase(prefix));
  for (char c = 'a'; c <= 'z'; c++) {
    getCompletionsHelper(prefix + c, lex, result);
  }
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
