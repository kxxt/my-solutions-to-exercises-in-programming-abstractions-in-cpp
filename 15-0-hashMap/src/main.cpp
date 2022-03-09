#include "console.h"
#include "stringmap.h"
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  cout << "Tests for StringMap:" << endl;
  StringMap map;
  // it should be empty
  assert(!map.get("asfadgf"));

  map.put("Hello", "World");
  assert(map.get("Hello") == "World");
  // get it for a second time.
  assert(map.get("Hello") == "World");

  // modify previous item
  map.put("Hello", "asd");
  assert(map.get("Hello") == "asd");

  // add a second item
  map.put("Hda asfds", "234");
  // the first item should still be there
  assert(map.get("Hello") == "asd");
  // test the second item
  assert(map.get("Hda asfds") == "234");

  cout << "OK" << endl;
  return 0;
}
