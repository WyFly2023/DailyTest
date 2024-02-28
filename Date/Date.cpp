//
// Created by wyf on 2024/1/31.
//

#include "Date.h"

Date::Date(int year, int month, int day) {
    _year = year;
    _month = month;
    _day = day;
}

Date::Date(const Date &d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

void Date::Print() const {
    cout << _year << "/" << _month << "/" << _day << endl;
}

Date &Date::operator=(const Date &d) {
    if (this != &d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}

bool Date::operator==(Date &d) const {
    return _year == d._year
           && _month == d._month
           && _day == d._day;
}

bool Date::operator<(Date &d) const {
    if (_year < d._year) {
        return true;
    } else if (_year == d._year) {
        if (_month < d._month) {
            return true;
        } else if (_month == d._month) {
            if (_day < d._day)
                return true;
        }
    }
    return false;
}

bool Date::operator>(Date &d) const {
    return !(*this <= d);
}

bool Date::operator>=(Date &d) const {
    return !(*this < d);
}

bool Date::operator<=(Date &d) const {
    return *this < d || *this == d;
}

bool Date::operator!=(Date &d) const {
    return !(*this == d);
}

//+和+=完整实现一个就行
Date &Date::operator+=(int day) {
    _day += day;
    while (_day > getMonthDay(_year, _month)) {
        _day -= getMonthDay(_year, _month);
        _month++;

        if (_month == 13) {
            _year++;
            _month = 1;
        }
    }
    return *this;
}

Date Date::operator+(int day) {
    Date tmp(*this);
//    tmp._day += day;
//    while (tmp._day > getMonthDay(tmp._year, tmp._month)) {
//        tmp._day -= getMonthDay(tmp._year, tmp._month);
//        tmp._month++;
//
//        if (tmp._month == 13) {
//            tmp._year++;
//            tmp._month = 1;
//        }
//    }
    //可以使用已经实现的 +=
    tmp += day;
    return tmp;
}