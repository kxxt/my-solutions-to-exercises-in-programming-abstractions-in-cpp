#include <fstream>
#include <iostream>

using namespace std;

ifstream getFile() {
  cout << "Please enter file name: ";
  string fn;
  cin >> fn;
  ifstream ifs(fn);
  return ifs;
}

int main() {
  auto ifs = getFile();
  string line, longest;
  while (getline(ifs, line))
    if (line.length() > longest.length()) longest = line;
  ////////////////////////////////////////////////////////
  cout << longest << endl;
  return 0;
}
