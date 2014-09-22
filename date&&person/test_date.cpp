#include "Date.h"
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

int main(int argc, const char *argv[])
{
    Date d;
    assert(!d.isValid());
    d.setToday();
    cout << "Today : " << d.toString() << endl;
    cout << "Today Format : " << d.toFormatString() << endl;
    
    cout << "今天是2014年的第 " << d.calDaysOfYear() << "天" << endl;
    cout << "今年还剩 " << d.calLeftDaysOfYear() << "天" << endl;


    Date d2(1993, 6, 27);
    cout << Date::differenceDate(d, d2) << endl;

    return 0;
}
