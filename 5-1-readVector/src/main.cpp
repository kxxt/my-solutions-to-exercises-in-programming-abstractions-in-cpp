#include <fstream>
#include <iostream>
#include <string>

#include "console.h"
#include "vector.h"

using namespace std;

// Macros

#define TRY_READ_VECTOR(T)                                                     \
  {                                                                            \
    ifstream ifs(#T ".txt");                                                   \
    Vector<T> v;                                                               \
    cout << #T << endl;                                                        \
    readVector(ifs, v);                                                        \
    cout << "#1" << endl << v << endl;                                         \
    readVector(ifs, v);                                                        \
    cout << "#2" << endl << v << endl;                                         \
    readVector(ifs, v);                                                        \
    cout << "#3" << endl << v << endl;                                         \
    cout << endl;                                                              \
  }

// Prototypes

void readVector(istream &is, Vector<int> &v);
void readVector(istream &is, Vector<long> &v);
void readVector(istream &is, Vector<double> &v);
void readVector(istream &is, Vector<string> &v);

int main() {
  TRY_READ_VECTOR(double)
  TRY_READ_VECTOR(int)
  TRY_READ_VECTOR(string)
  return 0;
}

bool isWhiteSpace(string const &str) {
  return str.find_first_not_of(" \t\n\v\f\r") == std::string::npos;
}

void readVector(istream &is, Vector<int> &v) {
  string line;
  while (getline(is, line))
    if (isWhiteSpace(line))
      break;
    else
      v.add(stoi(line));
}

void readVector(istream &is, Vector<long> &v) {
  string line;
  while (getline(is, line))
    if (isWhiteSpace(line))
      break;
    else
      v.add(stol(line));
}

void readVector(istream &is, Vector<double> &v) {
  string line;
  while (getline(is, line))
    if (isWhiteSpace(line))
      break;
    else
      v.add(stod(line));
}

void readVector(istream &is, Vector<string> &v) {
  string line;
  while (getline(is, line))
    if (isWhiteSpace(line))
      break;
    else
      v.add(line);
}
