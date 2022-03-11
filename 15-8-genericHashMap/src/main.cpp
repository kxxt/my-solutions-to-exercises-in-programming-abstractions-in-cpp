#include <cassert>
#include <iostream>

#include "console.h"
#include "hashcodes.h"
#include "myhashmap.h"
using namespace std;

int main() {
  cout << "Tests for StringMap:" << endl;
  HashMap<string, string> map;
  // it should be empty
  assert(map.size() == 0);
  assert(!map.get("asfadgf"));

  map.put("Hello", "World");
  assert(map.size() == 1);
  assert(map.get("Hello") == "World");
  // get it for a second time.
  assert(map.get("Hello") == "World");

  // modify previous item
  map.put("Hello", "asd");
  assert(map.get("Hello") == "asd");
  assert(map.size() == 1);

  // add a second item
  map.put("Hda asfds", "234");
  assert(map.size() == 2);
  // the first item should still be there
  assert(map.get("Hello") == "asd");
  // test the second item
  assert(map.get("Hda asfds") == "234");

  // trigger a rehash
  for (auto i = 0; i < 15; i++)
    map.put(to_string(i), to_string(i) + "***");
  assert(map.size() == 17);
  for (auto i = 0; i < 15; i++)
    assert(map.get(to_string(i)) == to_string(i) + "***");
  assert(map.get("Hello") == "asd");
  assert(map.get("Hda asfds") == "234");

  HashMap<int, short> ismap;
  ismap.put(1213, 1233);
  assert(ismap.get(1213) == 1233);

  cout << "OK" << endl;
  return 0;
}
