#include "Stack.hpp"
#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        Stack<int> s1;
        s1.push(7);

        cout << s1.top() << endl;
        s1.pop();

        Stack<string, deque<string> > s2;

        s2.push("foo");
        s2.push("bar");
        s2.push("hel");

        while(!s2.empty())
        {
            cout << s2.top() << endl;
            s2.pop();
        }

    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
