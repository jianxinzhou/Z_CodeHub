#include <iostream>
#include <string>
using namespace std;

class People
{
    public:
        // 默认构造函数
        People()
        {
            cout << "People()" << endl;
        }
        
        People(const string &name)
            : name_(name)
        {
            cout << "People(const string &name)" << endl;
        }

        People(string &&name)
            : name_(name)
        {
            cout << "People(string &&name)" << endl;
        }
        
        // 拷贝构造函数
        People(const People &p)
            : name_(p.name_)
        {
            cout << "People(const People &p)" << endl;
        }

        // 移动构造函数
        People(People &&p)
            : name_(p.name_)
        {
            cout << "People(People &&p)" << endl;
        }

    private:
        string name_;
};

int main(int argc, const char *argv[])
{
    People p1("hello");
    cout << "1--------------------" << endl << endl;

    string s;
    People p2(s);
    cout << "2--------------------" << endl << endl;

    People p3(p2);
    cout << "3--------------------" << endl << endl;

    People p4(People("hello")); //编译器进行了优化，直接用"hello"去移动构造p4了
    cout << "4--------------------" << endl << endl;

    People p5(std::move(p3));
    cout << "5--------------------" << endl << endl;


    return 0;
}



/*
Output:

People(string &&name)
1--------------------

People(const string &name)
2--------------------

People(const People &p)
3--------------------

People(string &&name)
4--------------------

People(People &&p)
5--------------------

*/
