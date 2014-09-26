#include "Integer.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Integer a;
    cout << a << endl;

    Integer b(10);
    cout << b << endl;

    cin >> b;
    cout << "b = " << b << endl;

    cout << "++b = " << ++b << endl;
    cout << "b++ =" << b++ << endl;
    cout << "b = " << b << endl;

    b = 13;
    cout << "b = " << b << endl;

    int i = (int)b;
    cout << "i = " << i << endl;

    return 0;
}
