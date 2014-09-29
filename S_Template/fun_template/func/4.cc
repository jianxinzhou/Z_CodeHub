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
    // 1
    cout << ::max(4, static_cast<int>(8.7)) << endl;

    // 2
    cout << ::max<int>(3, 6.5) << endl;

   

    return 0;
}




