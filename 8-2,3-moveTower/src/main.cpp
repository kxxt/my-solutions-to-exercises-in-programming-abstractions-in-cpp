#include "console.h"
#include "recursion.h"
#include "stack.h"
#include <iostream>
using namespace std;

void moveTower(unsigned n, char source, char dest, char tmp);

void moveTowerIterative(unsigned n, char source, char dest, char tmp);

int main() {
  moveTower(3, 'A', 'B', 'C');
  cout << endl << endl;
  moveTowerIterative(3, 'A', 'B', 'C');
  return 0;
}

void moveOneTower(char source, char dest) {
  cout << "move 1 tower from " << source << " to " << dest << endl;
}

void moveTower(unsigned n, char source, char dest, char tmp) {
  if (n == 0)
    return;
  moveTower(n - 1, source, tmp, dest);
  moveOneTower(source, dest);
  moveTower(n - 1, tmp, dest, source);
}

struct TowerMoveTask {
  unsigned n;
  char source, dest, tmp;
  TowerMoveTask(unsigned n, char source, char dest, char tmp) {
    this->n = n;
    this->source = source;
    this->dest = dest;
    this->tmp = tmp;
  }
};

void moveTowerIterative(unsigned n, char source, char dest, char tmp) {
  Stack<TowerMoveTask> stack{TowerMoveTask(n, source, dest, tmp)};
  while (!stack.isEmpty()) {
    auto task = stack.pop();
    if (task.n == 1)
      cout << task.source << " -> " << task.dest << endl;
    else {
      // First In Last Out
      stack.push(TowerMoveTask(task.n - 1, task.tmp, task.dest, task.source));
      stack.push(TowerMoveTask(1, task.source, task.dest, task.tmp));
      stack.push(TowerMoveTask(task.n - 1, task.source, task.tmp, task.dest));
    }
  }
}
