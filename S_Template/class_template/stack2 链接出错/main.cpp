#include "Stack.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        Stack<int> s1;
        s1.push(7);

        cout << s1.top() << endl;
        s1.pop();

        s1.pop(); //throw

    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
