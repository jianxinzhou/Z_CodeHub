#include "Person.h"
using namespace std;

Person::Person(const string &name, Date date)
    :name_(name), birthday_(date)
{

}


int Person::howlongAlive() const
{
    Date t;
    t.setToday();
    return Date::differenceDate(t, birthday_);
}

bool Person::isCelebrated() const
{
    Date today;
    today.setToday();
    Date d(today.getYear(), birthday_.getMonth(), birthday_.getDay());
    //d代表今年过生日的日期
    return Date::differenceDate(today, d) > 0;
}













