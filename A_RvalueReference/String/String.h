#ifndef _STRING_H_
#define _STRING_H_ 

#include "string.h"   // strcpy

class String
{
    public:
        String();                // 默认构造函数 
        String(const char *);    // 转化语义
        String(const String &);  // 拷贝构造函数
        String(String &&);       // 移动构造函数
        ~String();               // 析构函数

        String &operator=(const String &); // 复制赋值运算符
        String &operator=(String &&);      // 移动赋值运算符

    private:
        char *data_;
};

// 默认构造函数
String::String()
    : data_(new char[1])
{
    *data_ = 0;
}

// 转化语义
String::String(const char *s)
    : data_(new char[strlen(s) + 1])
{
    ::strcpy(data_, s);
}

// 拷贝构造函数
String::String(const String &s)
    : data_(new char[strlen(s.data_) + 1])
{
    ::strcpy(data_, s.data_);
}

// 移动构造函数
String::String(String &&s)
    : data_(s.data_)
{
    s.data_ = NULL; // s所封装指针data_的资源已被偷走，指针置为NULL，防止其析构时释放资源
}

// 复制赋值运算符
String &String::operator=(const String &s)
{
    if(this != &s)
    {
        delete[] data_;
        data_ = new char[strlen(s.data_) + 1];
        ::strcpy(data_, s.data_);
    }
    return *this;
}

// 移动赋值运算符
String &String::operator=(String &&s)
{
    if(this != &s)
    {
        delete[] data_;
        data_ = s.data_;
        s.data_ = NULL; // s所封装指针data_的资源已被偷走，指针置为NULL，防止其析构时释放资源
    }
    return *this;
}

//析构函数
String::~String()
{
    delete[] data_;
}



#endif  /*_STRING_H_*/
