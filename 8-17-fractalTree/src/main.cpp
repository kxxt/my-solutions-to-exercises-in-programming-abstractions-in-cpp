#include "gwindow.h"
#include <iostream>
using namespace std;

const double WINDOW_WIDTH = 720, WINDOW_HEIGHT = 720;
const double LINE_WIDTH = 1.8;

void drawTreeHelper(GWindow &window, double x, double y, double size, int order,
                    double direction, int currentOrder);
void drawTree(GWindow &window, double x, double y, double size, int order);
int main() {
  GWindow gw(WINDOW_WIDTH, WINDOW_HEIGHT);
  gw.setLineWidth(LINE_WIDTH);
  drawTree(gw, 0, 0, WINDOW_HEIGHT, 8);
  return 0;
}

void drawTree(GWindow &window, double x, double y, double size, int order) {
  if (order < 0 || x < 0 || y < 0 || size < 0)
    throw "Argument can't be negative!";
  else if (order == 0)
    return;
  drawTreeHelper(window, x + size / 2, y + size, size / 2, order, 90, 1);
}

void drawTreeHelper(GWindow &window, double x, double y, double size, int order,
                    double direction, int currentOrder) {
  static const double DELTA = 45;
  if (order == currentOrder) {
    window.setColor(0x2e8b57);
    window.drawPolarLine(x, y, size, direction);
    return;
  }
  window.setColor(0x8b7765);
  auto next = window.drawPolarLine(x, y, size, direction);
  ++currentOrder;
  size /= 2;
  drawTreeHelper(window, next.getX(), next.getY(), size, order,
                 direction - DELTA, currentOrder);
  drawTreeHelper(window, next.getX(), next.getY(), size, order,
                 direction + DELTA, currentOrder);
}
