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
    int i = 42;
    cout << ::max(7, i) << endl;

    double f1 = 3.4;
    double f2 = -6.7;
    cout << ::max(f1, f2) << endl;

    string s1 = "hello";
    string s2 = "world";
    cout << ::max(s1, s2) << endl;


    return 0;
}

