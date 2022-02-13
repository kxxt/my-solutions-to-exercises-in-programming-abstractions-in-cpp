#include "console.h"
#include "gwindow.h"
#include "random.h"
#include <cmath>
#include <iostream>
using namespace std;

const double WINDOW_HEIGHT = 480;
const double WINDOW_WIDTH = 720;
const double THICKNESS = 1.8;
const unsigned DELTA_THETA = 60;

GPoint drawCoastlineHelper(GWindow &window, GPoint start, double length,
                           int direction, unsigned order, unsigned targetOrder);
void drawCoastline(GWindow &window, GPoint start, double length,
                   unsigned order);

int main() {
  GWindow window(WINDOW_WIDTH, WINDOW_HEIGHT, true);
  drawCoastline(window, GPoint(0, WINDOW_HEIGHT / 2), WINDOW_WIDTH, 5);
  return 0;
}

void drawCoastline(GWindow &window, GPoint start, double length,
                   unsigned order) {
  window.setColor("Black");
  window.setLineWidth(THICKNESS);
  drawCoastlineHelper(window, start, length, 0, 0, order);
}

GPoint drawCoastlineHelper(GWindow &window, GPoint start, double length,
                           int direction, unsigned order,
                           unsigned targetOrder) {
  if (order == targetOrder) // base case
    return window.drawPolarLine(start, length, direction);
  double nextLength = length / 3, sign = 1;
  order++;
  auto next = drawCoastlineHelper(window, start, nextLength, direction, order,
                                  targetOrder);
  if (randomBool())
    sign = -1;
  next =
      drawCoastlineHelper(window, next, nextLength,
                          direction + sign * DELTA_THETA, order, targetOrder);
  next =
      drawCoastlineHelper(window, next, nextLength,
                          direction - sign * DELTA_THETA, order, targetOrder);
  next = drawCoastlineHelper(window, next, nextLength, direction, order,
                             targetOrder);
  return next;
}
