#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int &max(const int &a, const int &b)
{
    return a > b ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b, const T &c)
{
    return ::max(::max(a, b), c);
}

int main(int argc, const char *argv[])
{
    ::max(7, 42, 68);  //3
    ::max(7.0, 43.5); //2 
    ::max('a', 'b'); // char 2
    ::max(7, 42);   // 1 int
    ::max<>(7, 42); // 指定去调用模板版本 2
    ::max<double>(7, 42); //2 
    ::max('a', 42.7); // char double  1

    return 0;
}

















