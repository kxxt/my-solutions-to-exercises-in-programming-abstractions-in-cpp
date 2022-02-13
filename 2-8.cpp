#include <iostream>

using namespace std;

void findEaster(int year, string& month, int& day);

int main(){
    string month;
    int day;
    findEaster(1848, month, day);
    cout << "1848: " << month << " " << day << endl;
}

void findEaster(int year, string& month, int& day){
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (19 * a + 23) % 30;
    int e;
    if(1700<=year && year < 1800) e = (2 * b + 4 * c + 6 * d + 3) % 7;
    else if(1800<=year && year<1900) e=(2 * b + 4 * c + 6 * d + 4) % 7;
    else throw logic_error("Not implemented yet!");
    
    int f = d + e;
    if (f <= 9) {
        month = "March";
        day = f + 22;
    } else {
        month = "April";
        day = f - 9;
    }
}