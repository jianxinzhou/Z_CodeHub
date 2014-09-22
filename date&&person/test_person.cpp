#include "Person.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    Person p("zhangsan", Date(1992, 10, 12));
    cout << p.howlongAlive() << endl;
    cout << p.isCelebrated() << endl;
    return 0;
}



