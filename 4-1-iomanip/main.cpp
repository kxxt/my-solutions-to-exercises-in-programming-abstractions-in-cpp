#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double const PI = 3.141592653545;

inline double toRadian(int degree) { return degree * PI / 180; }

int main() {
  cout << " theta | sin(theta) | cos(theta) |" << endl
       << "----------------------------------" << endl;
  for (int theta = -90; theta <= 90; theta += 15) {
    cout << fixed << right << setprecision(7) << "  " << setw(3) << theta
         << "  | " << setw(10) << sin(toRadian(theta)) << " |  " << setw(9)
         << cos(toRadian(theta)) << " |" << endl;
  }
  return 0;
}
