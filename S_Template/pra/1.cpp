#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print(const T &t)
{
    // 注意不要遗漏 typename
    for(typename T::const_iterator it = t.begin();
        it != t.end();
        ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main(int argc, const char *argv[])
{
    vector<int> vec;
    vec.push_back(1);
    print(vec);
    return 0;
}
