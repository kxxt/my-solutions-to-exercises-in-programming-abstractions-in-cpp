#include "console.h"
#include <iostream>
using namespace std;

string reverse(string const &str);

int main() {
  cout << reverse("Hello, world!") << endl;
  return 0;
}

string reverse(string const &str) {
  if (str.length() <= 1)
    return str;
  else
    return reverse(str.substr(1)) + str[0];
}
