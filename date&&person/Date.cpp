#include "Date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


const int Date::kDaysOfMonth[2][12] = 
{
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

const string Date::kNameOfMonth[12] = 
{
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};


Date::Date()
    :year_(0),
     month_(0),
     day_(0)
{

}

Date::Date(int year,
           int month,
           int day)
    :year_(year),
     month_(month),
     day_(day)
{
}

bool Date::isLeapYear() const
{
    return (year_%4 == 0 && year_%100 != 0) || year_%400 == 0;
}

bool Date::isValid() const
{
    return year_ > 0 
           && month_ > 0
           && month_ <= 12
           && day_ > 0
           && day_ <= kDaysOfMonth[isLeapYear()][month_-1];
}

void Date::assertValid() const
{
    if(!isValid())
        abort();
}

int Date::calDaysOfYear() const
{
    assertValid();
    int leap = isLeapYear();
    int result = 0;
    for(int i = 1; i < month_; ++i)
    {
        result += kDaysOfMonth[leap][i-1];
    }
    result += day_;

    return result;
}

int Date::calLeftDaysOfYear() const
{
    bool leap = isLeapYear();
    int days = calDaysOfYear();
    if(leap == true)
        return 366 - days;
    else
        return 365 - days;
}

int Date::compareDate(const Date &other) const
{
    assertValid();
    other.assertValid();

    int res = year_ - other.year_;
    if(res == 0)
        res = month_ - other.month_;
    if(res == 0)
        res = day_ - other.day_;

    return res;
}


void Date::setDate(int year, int month, int day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}

void Date::setToday()
{
    time_t t = time(NULL);
    struct tm *pt = localtime(&t);
    if(pt == NULL)
    {
        perror("localtime");
        exit(EXIT_FAILURE);
    }

    year_ = pt->tm_year + 1900;
    month_ = pt->tm_mon + 1;
    day_ = pt->tm_mday;
}

string Date::toString() const
{
    assertValid();
    //2009 7/31
    char text[100] = {0};
    snprintf(text, sizeof text, "%04d %02d %02d", year_, month_, day_);
    return string(text);
}

string Date::toFormatString() const
{
    assertValid();
    //22 September 2014
    char text[1024] = {0};
    snprintf(text, sizeof text, "%d %s %04d", day_, kNameOfMonth[month_-1].c_str(), year_);
    return string(text);
}


int Date::differenceDate(const Date &d1, const Date &d2)
{
    Date t1, t2;  //t1 < t2
    bool minus = false;
    int days = 0;

    int diff = d1.compareDate(d2);
    if(diff == 0)
        return 0;
    else if(diff < 0) //d1 < d2
    {
        t1 = d1;
        t2 = d2;
        minus = true;
    }
    else if(diff > 0)
    {
        t1 = d2;
        t2 = d1;
        minus = false;
    }


    //只需比较t1与t2
    //这里保证t1 < t2
    //只需计算出天数的差距

    if(t1.year_ == t2.year_) //同一年
        days = t2.calDaysOfYear() - t1.calDaysOfYear();
    else
    {
        days += t1.calLeftDaysOfYear(); //t1剩余的天数
        for(int i = t1.year_+1; i <= t2.year_-1 ; ++i)
        {
            bool leap = (i%4 == 0 && i%100 != 0) || i%400 == 0;
            days += (leap == true ? 366 : 365); 
        }
        days += t2.calDaysOfYear();   //t2的天数
    }

    if(minus == true)
        return -1 * days;
    else
        return days;
}



