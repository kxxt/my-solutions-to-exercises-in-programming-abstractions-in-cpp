#include<iostream>
#include<cstdlib>

using namespace std;

bool tossCoin();

int main(){
    srand(time(NULL));
    int n=0, cnt=0;
    while(cnt<3){
        if(tossCoin()){
            cout << "heads" << endl;
            cnt++;
        }else{
            cout << "tails" << endl;
            cnt=0;
        }
        n++;
    }
    cout << "It took " << n << " times to get three heads in a row." << endl;
    return 0;
}

bool tossCoin(){
    return rand() % 2;
}