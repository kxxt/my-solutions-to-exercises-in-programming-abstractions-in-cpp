#include "calendar.h"
#include <stdexcept>
#include <string>

bool isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int daysInMonth(int year, Month month){
    switch(month){
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            return 31;
        case April:
        case June:
        case September:
        case November:
            return 30;
        case February:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

std::string monthToString(Month month){
    switch(month){
        case Month::January:
            return "January";
        case Month::February:
            return "February";
        case Month::March:
            return "March";
        case Month::April:
            return "April";
        case Month::May:
            return "May";
        case Month::June:
            return "June";
        case Month::July:
            return "July";
        case Month::August:
            return "August";
        case Month::September:
            return "September";
        case Month::October:
            return "October";
        case Month::November:
            return "November";
        case Month::December:
            return "December";
        default:
            throw std::runtime_error("Invalid month");
    }

}