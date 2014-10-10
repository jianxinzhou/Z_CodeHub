#include <iostream>
#include <string>
#include <assert.h>
#include "CountPtr.hpp"
using namespace std;

class Test
{
public:
    Test() { cout << "Test" << endl; }
    ~Test() { cout << "~Test" << endl; }

private:
    Test(const Test &);
    void operator=(const Test &);
};

int main(int argc, char const *argv[])
{
    CounterPtr<Test> ptr(new Test);
    cout << ptr.count() << endl;
    assert(ptr.count() == 1);


    CounterPtr<Test> ptr2(ptr);
    cout << ptr.count() << endl; //2

    CounterPtr<Test> ptr3;
    ptr3 = ptr;
    cout << ptr.count() << endl; //3

    if(ptr)
    {
        cout << "ptr is not NULL" << endl;
    }

    assert(!ptr.unique());
    return 0;
}



/*
Output:

Test
1
2
3
ptr is not NULL
~Test

*/
