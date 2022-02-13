#include "gwindow.h"
#include <iostream>
using namespace std;

const double WINDOW_WIDTH = 720, WINDOW_HEIGHT = 480;
const double LINE_WIDTH = 1.8;

void drawHFractal(GWindow &gw, double x, double y, double size, int order);

void drawHFractalHelper(GWindow &gw, double x, double y, double size, int order,
                        int currentOrder);

int main() {
  GWindow window(WINDOW_WIDTH, WINDOW_HEIGHT);
  drawHFractal(window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2,
               7);
  return 0;
}

void drawHFractal(GWindow &gw, double x, double y, double size, int order) {
  gw.setColor("Black");
  gw.setLineWidth(LINE_WIDTH);
  drawHFractalHelper(gw, x, y, size, order, 0);
}

void drawHFractalHelper(GWindow &gw, double x, double y, double size, int order,
                        int currentOrder = 0) {
  static const int dxs[]{-1, 1}, dys[]{-1, 1};
  double halfSize = size / 2;
  gw.drawLine(x - halfSize, y, x + halfSize, y); // --
  gw.drawLine(x - halfSize, y - halfSize, x - halfSize,
              y + halfSize); // Left |
  gw.drawLine(x + halfSize, y - halfSize, x + halfSize,
              y + halfSize); // Right |
  if (currentOrder == order)
    return;
  for (int dx : dxs)
    for (int dy : dys)
      drawHFractalHelper(gw, x + dx * halfSize, y + dy * halfSize, halfSize,
                         order, currentOrder + 1);
}
