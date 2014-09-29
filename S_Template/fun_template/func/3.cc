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
    //编译错误
    cout << ::max(4, 4.7) << endl;
    return 0;
}




