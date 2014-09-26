#include "String.h"
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


String::String()
    :str_(new char[1])
{
    *str_ = 0; // 0 \0
}

String::String(const char *s)
    :str_(new char[strlen(s) + 1])
{
    ::strcpy(str_, s);
}

String::String(const String &s)
    :str_(new char[s.size() + 1])
{
    ::strcpy(str_, s.str_);
}

String::~String()
{
    delete[] str_;
}

String &String::operator=(const String &s)
{
    if(this != &s)
    {
        delete[] str_;
        str_ = new char[s.size() + 1];
        ::strcpy(str_, s.str_);
    }

    return *this;
}

/* 实际上没有该函数，传入字符串也是可行的，
 * 因为有构造函数String::String(const char *s)
 * 当需要String对象时，字符串会隐式转换成String对象
 * 此处为了避免这种开销，因此自定义字符串赋值的操作符
 */
String &String::operator=(const char *s)
{
    if(str_ != s)
    {
        delete[] str_;
        str_ = new char[strlen(s) + 1];
        ::strcpy(str_, s);
    }

    return *this;
}


void String::debug() const
{
    cout << str_ << endl;
}

String &String::operator+=(const String &s)
{
    // "foo" + "bar"
    char *st = new char[size() + s.size() + 1];
    ::strcpy(st, str_); // "foo"
    ::strcat(st, s.str_); // "foobar";

    delete[] str_;
    str_ = st;

    return *this;
}

String &String::operator+=(const char *s)
{
    char *st = new char[size() + strlen(s) + 1];
    ::strcpy(st, str_);
    ::strcat(st, s);

    delete[] str_;
    str_ = st;

    return *this;
}

//如果+号重载为成员函数，而非友元形式，就失去了(char* + String)的重载功能
String operator+(const String &s1, const String &s2)
{
    String st(s1);
    st += s2;

    return st;
}

String operator+(const String &s1, const char *s2)
{
    return s1 + String(s2);
}

String operator+(const char *s1, const String &s2)
{
    return String(s1) + s2;
}


bool operator<  (const String &s1, const String &s2)
{
    return ::strcmp(s1.str_, s2.str_) < 0;
}

bool operator<= (const String &s1, const String &s2)
{
    //s1 <= s2 -> !(s1 > s2)
    return !(s1 > s2);
}

bool operator>  (const String &s1, const String &s2)
{
    //s1 > s2 -> s2 < s1;
    return s2 < s1;
}

bool operator>= (const String &s1, const String &s2)
{
    return !(s1 < s2);
}

bool operator== (const String &s1, const String &s2)
{
    return ::strcmp(s1.str_, s2.str_) == 0;
}

bool operator!= (const String &s1, const String &s2)
{
    return !(s1 == s2);
}


char &String::operator[] (size_t index)
{
    return str_[index];
}

char String::operator[] (size_t index) const
{
    return str_[index];
}   

//为String可以提供一个高效的swap版本，仅仅交换指针即可。
//如果直接调用标准库函数swap来交换两个String对象，那么
//会调用拷贝构造函数和赋值运算符，进行一次复制和两次赋值
//这回导致深拷贝，增加开销，具体过程大致如下
//String temp = S1; 调用拷贝构造函数
//S1 = S2;          调用赋值运算符
//S2 = temp;        调用赋值运算符
void String::swap(String &other)
{
    std::swap(str_, other.str_);
}

