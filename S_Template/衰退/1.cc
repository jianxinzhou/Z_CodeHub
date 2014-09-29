#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}


int main(int argc, const char *argv[])
{
    string s = "hello";

    /* 引用传递，不会导致数组类型到指针的退化 */
 
    //"hello"类型为const char[6]，"world"类型为const char[6]，实例化模板没有问题
    ::max("hello", "world");

    //"apple"类型为const char[6]，"orange"类型为const char[7]，类型不一致，实例化模板报错 
    ::max("apple", "orange");

    //"apple"类型为const char[6]，s类型为string，实例化模板报错
    ::max("apple", s);

    return 0;
}


