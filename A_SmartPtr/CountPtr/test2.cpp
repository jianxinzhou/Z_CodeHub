#include <iostream>
#include <string>
#include <vector>
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

    vector<CounterPtr<Test> > coll;
    coll.push_back(ptr);

    cout << "count = " << ptr.count() << endl;
    assert(!ptr.unique());

    return 0;
}
