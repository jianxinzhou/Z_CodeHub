#include "Array.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void print(const T &t)
{
    for(typename T::const_iterator it = t.begin();
        it != t.end();
        ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Array<int, 20> arr;

    for(Array<int, 20>::size_type ix = 0; ix != arr.size(); ++ix)
    {
        arr[ix] = ix;
    }

    for(Array<int, 20>::const_iterator it = arr.begin();
        it != arr.end();
        ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    print(arr);

    Array<int, 20>::const_iterator it = std::find(arr.begin(), arr.end(), 15);
    cout << *it << endl;


    return 0;
}