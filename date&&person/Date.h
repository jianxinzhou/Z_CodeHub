#ifndef DATE_H_
#define DATE_H_ 

#include <string>

class Date
{
    public:
        Date();
        Date(int year, int month, int day);
        
        void assertValid() const;
        bool isValid() const;
        bool isLeapYear() const;
        int calDaysOfYear() const;
        int calLeftDaysOfYear() const;
        int compareDate(const Date &other) const;

        void setDate(int year, int month, int day);
        void setToday();

        std::string toString() const;
        std::string toFormatString() const;


        int getYear() const
        { return year_; }
        int getMonth() const
        { return month_; }
        int getDay() const
        { return day_; }

        static int differenceDate(const Date &t1, const Date &t2);

    private:
        int year_;
        int month_;
        int day_;

        static const int kDaysOfMonth[2][12];
        static const std::string kNameOfMonth[12];
};

#endif  /*DATE_H_*/
