#include "console.h"
#include "queue.h"
#include "stack.h"
#include <iostream>

using namespace std;

void reverseQueue(Queue<string> &queue);

int main() {
  Queue<string> q{"1223", "adsf", "saedrf", "fsadsdgf", "fsad"};
  reverseQueue(q);
  cout << q << endl;
  return 0;
}

void reverseQueue(Queue<string> &queue) {
  Stack<string> stack;
  while (!queue.isEmpty())
    stack.push(queue.dequeue());
  while (!stack.isEmpty())
    queue.enqueue(stack.pop());
}
