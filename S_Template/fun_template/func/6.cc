#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T1, typename T2>
T1 max(const T1 &a, const T2 &b)
{
    return a > b ? a : b;
}
//返回值最好为传值



int main(int argc, const char *argv[])
{
    cout << ::max(3, 4.5) << endl;  

    return 0;
}




