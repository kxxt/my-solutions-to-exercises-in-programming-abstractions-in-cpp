#include "console.h"
#include "lexicon.h"
#include "set.h"
#include "simpio.h"
#include <iostream>
using namespace std;

Set<string> embededWords(Lexicon const &lex, const string &word);

void embededWordsHelper(Set<string> &ans, Lexicon const &lex,
                        const string &word, const string &cur);

int main() {
  Lexicon lex("dictionary.txt");
  while (true) {
    auto word = getLine("Enter starting word: ");
    auto result = embededWords(lex, word);
    for (auto const &w : result)
      cout << "  " << w << endl;
    cout << endl;
  }
  return 0;
}

Set<string> embededWords(Lexicon const &lex, const string &word) {
  Set<string> ans;
  embededWordsHelper(ans, lex, word, "");
  return ans;
}

void embededWordsHelper(Set<string> &ans, Lexicon const &lex,
                        const string &word, const string &cur) {
  if (word.length() == 0) {
    if (lex.contains(cur))
      ans.add(cur);
    return;
  }
  embededWordsHelper(ans, lex, word.substr(1), cur + word[0]); // Chosen
  embededWordsHelper(ans, lex, word.substr(1), cur);           // Not chosen
}
