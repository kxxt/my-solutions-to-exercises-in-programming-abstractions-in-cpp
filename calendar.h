#ifndef _calender_h

#define _calender_h

#include <string>
#include "enum_iterator.h"

enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

typedef Iterator<Month, Month::January, Month::December> MonthIterator;

int daysInMonth(int year, Month month);

std::string monthToString(Month month);

bool isLeapYear(int year);

#endif