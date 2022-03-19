#include "console.h"
#include "mypqueue.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main() {
  PriorityQueue<string, int> q;
  assert(q.size() == 0);
  q.enqueue("hello", 10);
  assert(q.peek() == "hello");
  assert(q.dequeue() == "hello");
  assert(q.size() == 0);
  for (int i = 0; i < 20; i++)
    q.enqueue(to_string(i), i);
  assert(q.size() == 20);
  // cout << q << endl;
  for (int i = 0; i < 20; i++) {
    assert(q.dequeue() == std::to_string(i));
    // cout << q << endl;
  }
  for (int i = 20; i > 0; i--)
    q.enqueue(to_string(i), i);
  for (int i = 1; i <= 20; i++)
    assert(q.dequeue() == std::to_string(i));
  cout << "All Tests Passed!" << endl;
  return 0;
}
