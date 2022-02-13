#include <iostream>
using namespace std;

long long int permutations(long long int n, long long int k){
    long long int prod = 1;
    for(long long int i = n; i > n-k; i--){
        prod *= i;
    }
    return prod;
}

int main(){
    cout << permutations(52,2) << endl;
}