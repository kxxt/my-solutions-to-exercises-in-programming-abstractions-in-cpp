#include <iostream>
#include <cmath>
using namespace std;

double my_sqrt(double x);
void test(double x);

int main()
{
    test(0);
    test(2.231);
    test(4);
    test(4.001);
    test(5);
    test(-1);
}

void test(double x)
{
    static int count = 0;
    cout << "test " << ++count << ":my_sqrt(" << x << ")" << "=" << my_sqrt(x) << ", sqrt(" << x << ")="  << sqrt(x) << endl;
}

/********************************************
 * sqrt impl using successive approximation *
 ********************************************/
double my_sqrt(double x)
{
    if(x<0) {
        throw std::runtime_error("x can't be negative!");
    }
    double g = x / 2;
    double l = min(g, 2.0);
    double r = max(g, 2.0);
    while (l != g)
    {
        g = (l + r) / 2.0;
        l = min(g, x / g);
        r = max(g, x / g);
    }
    return g;
}