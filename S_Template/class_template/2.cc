#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Test
{
    public:
        Test(const T &s) :data_(s) { }
        void print() const;

    private:
        T data_;
};

template <typename T>
void Test<T>::print() const
{
    cout << data_ << endl;
}


int main(int argc, const char *argv[])
{
    Test<int> t(12);
    t.print(); //12

    Test<string> t2("hello");
    t2.print(); // "hello"


    return 0;
}


