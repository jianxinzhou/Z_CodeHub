#include "Queue.hpp"
#include <string>
#include <list>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Queue<int> qt1;
    qt1.push(12);
    qt1.push(56);
    qt1.push(43);
    qt1.push(74);

    //qt1 Queue<int, deque<int> >
    //qt2 Queue<double, deque<double> >
    Queue<double> qt2(qt1);
    while(!qt2.empty())
    {
        cout << qt2.front() << endl;
        qt2.pop();
    }

    //qt1 Queue<int, deque<int> >
    //qt2 Queue<double, deque<double> >
    //qt3 Queue<double, list<double> >
    Queue<double, list<double> > qt3;
    qt3 = qt1;
    while(!qt3.empty())
    {
        cout << qt3.front() << endl;
        qt3.pop();
    }

    return 0;
}

