#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T1, typename T2>
const T1 &max(const T1 &a, const T2 &b)
{
    return a > b ? a : b;
}



int main(int argc, const char *argv[])
{
    cout << ::max(3, 4.5) << endl;  
    // int double
    // const int &max(const int &, const double &);
    // 因为T1与T2类型不同，所以进行强制类型转换
    // 产生了一个中间临时变量
    // 所以最后的返回值，引用了一个临时变量

    return 0;
}




