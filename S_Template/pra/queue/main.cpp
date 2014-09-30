#include "Queue.hpp"
#include <string>
#include <list>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    //Queue<string> qt;
    Queue<string, list<string> > qt;
    qt.push("foo");
    qt.push("bar");

    while(!qt.empty())
    {
        cout << qt.front() << endl;
        qt.pop();
    } 
    return 0;
}

