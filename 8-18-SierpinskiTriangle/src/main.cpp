#include "gwindow.h"
#include <iostream>
using namespace std;

const double WINDOW_WIDTH = 720, WINDOW_HEIGHT = 480;
const double LINE_WIDTH = 2;

void drawSierpinskiTriangle(GWindow &window, double x, double y, double size,
                            int order);

void drawSierpinskiTriangleHelper(GWindow &window, double x, double y,
                                  double size, int order, int currentOrder);

int main() {
  GWindow window(WINDOW_WIDTH, WINDOW_HEIGHT);
  drawSierpinskiTriangle(window, WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4,
                         int(WINDOW_HEIGHT * 0.8), 6);
  return 0;
}

void drawSierpinskiTriangle(GWindow &window, double x, double y, double size,
                            int order) {
  if (order < 0 || x < 0 || y < 0 || size < 0)
    throw "Argument can't be negative!";
  else if (order == 0)
    return;
  window.setColor("Black");
  drawSierpinskiTriangleHelper(window, x, y, size, order, 1);
}

void drawSierpinskiTriangleHelper(GWindow &window, double x, double y,
                                  double size, int order, int currentOrder) {
  if (order == currentOrder) {
    auto next = window.drawPolarLine(x, y, size, 0);
    next = window.drawPolarLine(next, size, -120);
    window.drawPolarLine(next, size, +120);
    return;
  }
  double halfSize = size / 2;
  ++currentOrder;
  drawSierpinskiTriangleHelper(window, x, y, halfSize, order, currentOrder);
  drawSierpinskiTriangleHelper(window, x + halfSize, y, halfSize, order,
                               currentOrder);
  drawSierpinskiTriangleHelper(window, x + halfSize / 2,
                               y + sqrt(3) * halfSize / 2, halfSize, order,
                               currentOrder);
}
