#include "Scoped_ptr.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

class Test
{
    public:
        Test()  { cout << "Test"  << endl; }
        ~Test() { cout << "~Test" << endl; }
};

int main(int argc, const char *argv[])
{
    ScopedPtr<Test> object(new Test);
    cout << "1------------------------------" << endl << endl;

    (*object).~Test();
    cout << "2------------------------------" << endl << endl;

    (*(object.get())).~Test();
    cout << "3------------------------------" << endl << endl;
    
    /*
    object.reset();
    assert(object.get() == NULL);
    cout << "4------------------------------" << endl << endl;
    */
    return 0;
}


/*
Output:

Test
1------------------------------

~Test
2------------------------------

~Test
3------------------------------

~Test

*/
