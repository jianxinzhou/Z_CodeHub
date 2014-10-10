#include "AutoPtr.hpp"
#include <iostream>
#include <assert.h>
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
    AutoPtr<Test> ptr(new Test);
    assert(ptr);

    AutoPtr<Test> ptr2(ptr);
    assert(!ptr);
    assert(ptr2);

    AutoPtr<Test> ptr3;
    assert(!ptr3);
    ptr3 = ptr2;
    assert(!ptr2);
    assert(ptr3);

    return 0;
}

/*
Output:

Test
~Test

*/
