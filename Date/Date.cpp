//
// Created by wyf on 2024/1/31.
//

#include "Date.h"

Date::Date(int year, int month, int day)
    :_year(year),_month(month),_day(day)
{
    if (!checkDate())
        cout << year << "/" << month << "/" << day << "：非法日期" << endl;
}

Date::Date(const Date &d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
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

Date Date::operator-(int day) {
    Date tmp = *this;
    tmp -= day;

    return tmp;
}

Date &Date::operator-=(int day) {
    _day -= day;
    while (_day <= 0) {
        _month--;
        if (_month == 0) {
            _year--;
            _month = 12;
        }
        _day += getMonthDay(_year, _month);
    }
    return *this;
}

//++day
Date &Date::operator++() {
    *this += 1;
    return *this;
}

//day++
Date Date::operator++(int) {
    Date tmp = *this;
    *this += 1;

    return tmp;
}

//--day
Date &Date::operator--() {
    *this -= 1;
    return *this;
}

//day--
Date Date::operator--(int) {
    Date tmp = *this;
    *this -= 1;

    return tmp;
}

int Date::operator-(const Date &d) {
    Date big = *this;
    Date small = d;
    int flag = 1;
    if (big < small) {
        flag = -1;
        big = d;
        small = *this;
    }
    int n = 0;
    while (big != small) {
        small++;
        n++;
    }
    return n * flag;
}

bool Date::checkDate() {
    //这里假设年份从0开始
    if (_year < 0 || _month < 1 || _month > 12 || _day > getMonthDay(_year, _month))
        return false;
    return true;
}

ostream &operator<<(ostream &_cout, const Date &d) {
    _cout << d._year << "/" << d._month << "/" << d._day << endl;
    return _cout;
}

istream &operator>>(istream &_cin, Date &d) {
    while (true) {
        _cin >> d._year >> d._month >> d._day;
        if (!d.checkDate())
            cout << "日期非法，请重新输入：";
        else
            break;
    }
    return _cin;
}