#include <iostream>
#include <cstdlib>

using namespace std;

double rand_real();

int main(){
    int n;
    cin >> n;
    double sum=0;
    for(int i=0;i<n;i++){
        sum += rand_real();
    }
    cout << sum/n << endl;
    return 0;
}

double rand_real(){
    return rand() / (double)RAND_MAX;
}