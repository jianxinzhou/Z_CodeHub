#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}


int main(int argc, const char *argv[])
{
    string s = "hello";
    
    /* 值传递，数组类型会退化为指针 */

    // const char *  vs   const char * 模板实例化正确
    ::max("hello", "world");

    // const char *  vs   const char * 模板实例化正确
    ::max("apple", "orange");

    // const char *  vs   string       模板实例化报错
    ::max("apple", s);

    return 0;
}


