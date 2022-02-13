#include<iostream>

using namespace std;

const int N = 10000;

bool isPerfect(int n);

int main(){
    for(int i =1;i<N;i++){
        if(isPerfect(i)){
            cout<<i<<endl;
        }
    }
    return 0;
}

bool isPerfect(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0) sum+=i;
    }
    return sum==n;
}