#include <iostream>
#include "calendar.h"

using namespace std;

int main(){
    int year;
    cin >> year;
    for(Month month: MonthIterator()){
        cout << monthToString(month) << " has " << daysInMonth(year, month) << " days" << endl;
    }
    return 0;
}