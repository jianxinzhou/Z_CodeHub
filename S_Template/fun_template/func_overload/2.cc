#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}

template <typename T>
const T *max(const T *a, const T *b)
{
    return *a > *b ? a : b;
}

const char *max(const char *a, const char *b)
{
    return ::strcmp(a, b) > 0 ? a : b;
}


int main(int argc, const char *argv[])
{
    int a = 7;
    int b = 42;
    ::max(a, b);  // 1


    string s = "hey";
    string t = "you";
    ::max(s, t);  // 1


    int *p1 = &b;
    int *p2 = &a;
    ::max(p1, p2); // 2

    const char *s1 = "David";
    const char *s2 = "Nico";
    ::max(s1, s2); // 3

    return 0;
}
















