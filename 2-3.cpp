#include <iostream>

using namespace std;

int no=0;

#define TEST_CASE(input, ans) \
    no++;\
    if (ans == roundToNearestInt(input)) \
        cout << "Case #" << no << ": " << "Passed" << endl; \
    else \
        cout << "Case #" << no << ": " << "Failed" << endl

int roundToNearestInt(float x);

int main(){
    TEST_CASE(1.0, 1);
    TEST_CASE(1.2, 1);
    TEST_CASE(1.5, 2);
    TEST_CASE(1.99999, 2);
    TEST_CASE(0, 0);
    TEST_CASE(-1, -1);
    return 0;
}

int roundToNearestInt(float x){
    if(x>=0) return (int)(x + 0.5);
    else return (int)(x - 0.5);
}