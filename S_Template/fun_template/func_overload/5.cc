#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}

//如果想在三个参数的max版本中调用这个函数
//必须把它放在前面
const int &max(const int &a, const int &b)
{
    cout << "mark" << endl;
    return a > b ? a : b;
}


template <typename T>
const T &max(const T &a, const T &b, const T &c)
{
    ::max(::max(a, b), c);
}


int main(int argc, const char *argv[])
{
    ::max(1, 2, 3);
    return 0;
}











