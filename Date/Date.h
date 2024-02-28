//
// Created by wyf on 2024/1/31.
//

#ifndef DATE_DATE_H
#define DATE_DATE_H

#include <iostream>

using namespace std;

class Date {
public:
    Date(int year = 2024, int month = 3, int day = 1);

    Date(const Date &d);

    void Print() const;

    Date &operator=(const Date &d);

    bool operator==(Date &d) const;

    bool operator<(Date &d) const;

    bool operator>(Date &d) const;

    bool operator>=(Date &d) const;

    bool operator<=(Date &d) const;

    bool operator!=(Date &d) const;

    //获取每月的天数
    int getMonthDay(int year, int month) {
        static int monthDays[13] =
                {0, 31, 28, 31, 30,
                 31, 30, 31, 31,
                 30, 31, 30, 31};

        //用来判断闰年，如果是则直接返回闰年的二月份天数
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
            return 29;

        return monthDays[month];
    }

    Date &operator+=(int day);

    Date operator+(int day);

private:
    int _year;
    int _month;
    int _day;
};


#endif //DATE_DATE_H
