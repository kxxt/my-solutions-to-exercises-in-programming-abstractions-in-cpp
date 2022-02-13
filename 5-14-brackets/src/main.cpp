#include "console.h"
#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

enum Reason { Ok, MissingClose, CloseBeforeOpen, ImproperlyNested };

Reason checkBrackets(string str);

int main() {
  cout << checkBrackets("{ s = 2 * (a[2] + 3); x = (1 + (2)); }") << endl;
  cout << checkBrackets("(([])") << endl;
  cout << checkBrackets(")(") << endl;
  cout << checkBrackets("{(})") << endl;
  return 0;
}

Reason checkBrackets(string str) {
  Stack<char> s;
  for (auto c : str) {
    switch (c) {
    case '(':
    case '[':
    case '{':
      s.push(c);
      break;
    case ')':
      if (s.isEmpty())
        return Reason::CloseBeforeOpen;
      if (s.pop() != '(')
        return Reason::ImproperlyNested;
      break;
    case ']':
      if (s.isEmpty())
        return Reason::CloseBeforeOpen;
      if (s.pop() != '[')
        return Reason::ImproperlyNested;
      break;
    case '}':
      if (s.isEmpty())
        return Reason::CloseBeforeOpen;
      if (s.pop() != '{')
        return Reason::ImproperlyNested;
      break;
    default:
      break;
    }
  }
  if (!s.isEmpty())
    return Reason::MissingClose;
  return Reason::Ok;
}
