#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

//传引用
template <typename T>
const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}

const char *&max(const char *&a, const char *&b)
{
    return ::strcmp(a, b) > 0 ? a : b;
}

//求3个任意类型的最大值
//传引用
template <typename T>
const T &max(const T &a, const T &b, const T &c)
{
    return ::max(::max(a, b), c);
    //::max(::max(s1, s2), s3); //返回的是一个临时的变量
    //这里将临时变量的引用返回出去，可能导致错误
    //const char *temp = ::max(::max(s1, s2), s3);
    //
}


int main(int argc, const char *argv[])
{
    ::max(7, 42, 68);

    const char *s1 = "fegfwe";
    const char *s2 = "Fwtfgt";
    const char *s3 = "geryhgr5";
    ::max(s1, s2, s3);


    return 0;
}




