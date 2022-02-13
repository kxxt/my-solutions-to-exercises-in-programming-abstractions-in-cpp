#include <iostream>
#include <string>

using namespace std;

int findDNAMatch(string const& s1, string const& s2, int start = 0);
string getComplementaryString(string str);

int main() {
  cout << findDNAMatch("TGC", "TAACGGTACGTC") << endl;
  cout << findDNAMatch("TTGCC", "TAACGGTACGTC") << endl;
  return 0;
}

int findDNAMatch(string const& s1, string const& s2, int start) {
  auto complementary = getComplementaryString(s1);
  auto pos = s2.find(complementary, start);
  if (pos == string::npos) return -1;
  return pos;
}

string getComplementaryString(string str) {
  for (char& ch : str) {
    switch (ch) {
      case 'A':
        ch = 'T';
        break;
      case 'C':
        ch = 'G';
        break;
      case 'G':
        ch = 'C';
        break;
      case 'T':
        ch = 'A';
        break;
      default:
        throw invalid_argument("`str` should only contain ACGT");
    }
  }
  return str;
}
