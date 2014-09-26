#include "SmartPtr.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    {
        SmartPtr ptr(new Animal);
        cout << ptr.getPtr() << endl;
         //ptr->run();
         ptr.operator->()->run();

        ptr.resetPtr(); //这里释放内存

        //Animal *pa = new Animal;

        ptr.resetPtr(new Animal);
        cout << ptr.getPtr() << endl;

        //delete pa;

    }
    return 0;
}
