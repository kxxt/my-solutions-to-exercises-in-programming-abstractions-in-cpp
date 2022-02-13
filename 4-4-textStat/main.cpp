#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

ifstream getFile() {
  cout << "Please enter file name: ";
  string fn;
  cin >> fn;
  ifstream ifs(fn);
  return ifs;
}

void statTextStream(istream& is, int&, int&, int&);
int countWords(string const&);
void prettyPrintStats(int, int, int);

int main() {
  auto ifs = getFile();
  int nChar, nWord, nLine;
  statTextStream(ifs, nChar, nWord, nLine);
  prettyPrintStats(nChar, nWord, nLine);
  return 0;
}

void prettyPrintStats(int nChar, int nWord, int nLine) {
  int maxlen = max(max(to_string(nChar).length(), to_string(nWord).length()),
                   to_string(nLine).length());
  cout << right << "Chars: \t" << setw(maxlen) << nChar << endl
       << "Words: \t" << setw(maxlen) << nWord << endl
       << "Lines: \t" << setw(maxlen) << nLine << endl;
}

void statTextStream(istream& is, int& nChar, int& nWord, int& nLine) {
  nChar = nWord = nLine = 0;
  string current;
  while (getline(is, current)) {
    nChar += current.length();
    nWord += countWords(current);
    nLine++;
  }
}

int countWords(string const& str) {
  int cnt = 0;
  bool inWord = false;
  for (auto ch : str) {
    if (isspace(ch)) {
      if (inWord) inWord = false;
    } else {
      if (!inWord) {
        cnt++;
        inWord = true;
      }
    }
  }
  return cnt;
}
