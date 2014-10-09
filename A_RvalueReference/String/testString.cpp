#include "string.h"   // strcpy
#include <iostream>
using namespace std;

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
    
    cout << "default" << endl;
}

// 转化语义
String::String(const char *s)
    : data_(new char[strlen(s) + 1])
{
    ::strcpy(data_, s);
    
    cout << "const char *" << endl;
}

// 拷贝构造函数
String::String(const String &s)
    : data_(new char[strlen(s.data_) + 1])
{
    ::strcpy(data_, s.data_);
    
    cout << "copy constructor" << endl;
}

// 移动构造函数
String::String(String &&s)
    : data_(s.data_)
{
    s.data_ = NULL; // s所封装指针data_的资源已被偷走，指针置为NULL，防止其析构时释放资源
    
    cout << "move constructor" << endl;
}

// 复制赋值运算符
String &String::operator=(const String &s)
{
    cout << "copy operator=" << endl;
    
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
    cout << "move operator=" << endl;

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


int main(int argc, const char *argv[])
{
    String s("foo"); // 调用const char * 版本的构造函数
    cout << "1------------------" << endl << endl;
    
    String s2(s);    // 调用拷贝构造函数
    cout << "2------------------" << endl << endl;

    String s3(String("bar")); // 此处编译器进行了优化，直接调用了 const char *版本的构造函数
    cout << "3------------------" << endl << endl;

    String s4(std::move(String("bar"))); // 此处调用了移动构造函数
    cout << "4------------------" << endl << endl;

    s3 = s; // 调用复制赋值运算符
    cout << "5------------------" << endl << endl;

    s3 = String("Hello"); // 调用移动赋值运算符 
    cout << "6------------------" << endl << endl;

    s3 = std::move(s);    // 调用移动赋值运算符，原来的左值对象s失效
   
    return 0;
}



/*
Output:

const char *
1------------------

copy constructor
2------------------

const char *
3------------------

const char *
move constructor
4------------------

copy operator=
5------------------

const char *
move operator=
6------------------

move operator=

*/
