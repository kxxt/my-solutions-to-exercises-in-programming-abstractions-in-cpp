#include <iostream>
#include <cstdlib>

using namespace std;

bool rand_bool();

int main()
{
    int n = 10000, year = 0;
    cout << "There are " << n << " atoms initially." << endl;
    while (n > 0)
    {
        int new_n = 0;
        for (int i = 0; i < n; i++)
        {
            if (rand_bool())
            {
                new_n++;
            }
        }
        cout << "There are " << new_n << " atoms at the end of the year " << ++year << "." << endl;
        n = new_n;
    }
    return 0;
}

bool rand_bool()
{
    return rand() > RAND_MAX / 2;
}