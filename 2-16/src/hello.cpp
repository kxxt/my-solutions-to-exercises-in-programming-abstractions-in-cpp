#include <iostream>
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
using namespace std;

const int WIDTH = 800, HEIGHT = 500;

int main() {
    GWindow window(WIDTH, HEIGHT);
    window.setColor("Cyan");
    window.fillRect(GRectangle(0,0,WIDTH,HEIGHT));
    window.setWindowTitle("Rainbow");
    window.setColor("Red");
    window.fillOval( -100, 100,  WIDTH+200,  1000);
    window.setColor("Orange");
    window.fillOval( -100, 140,  WIDTH+200,  1000);
    return 0;
}
