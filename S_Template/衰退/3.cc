#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

template <typename T>
void ref(const T &t)
{
    cout << "size of T :" << sizeof(T) << endl;
    //动态类型识别 RTTI
    cout << typeid(t).name() << endl;
}


template <typename T>
void nonref(T t)
{
    cout << "size of T :" << sizeof(T) << endl;
    cout << typeid(t).name() << endl;
}


int main(int argc, const char *argv[])
{
    ref("hello");
    nonref("world");
    return 0;
}



