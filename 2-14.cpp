#include <iostream>

using namespace std;

pair<double, double> rand_point();
bool isInCircle(pair<double, double>);

int main()
{
    int n;
    cin >> n;
    int in_circle = 0;
    for (int i = 0; i < n; i++)
    {
        pair<double, double> p = rand_point();
        if (isInCircle(p))
            in_circle++;
    }
    cout << double(in_circle) / n * 4 << endl;
    return 0;
}

double rand_real(double min, double max){
    return min + (max - min) * rand() / ((double) RAND_MAX + 1.0);
}

pair<double, double> rand_point(){
    double x = rand_real(-1,1);
    double y = rand_real(-1,1);
    return make_pair(x, y);
}

bool isInCircle(pair<double, double> p){
    return p.first * p.first + p.second * p.second <= 1;
}