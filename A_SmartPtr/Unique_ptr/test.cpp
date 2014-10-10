#include "UniquePtr.hpp"
#include <iostream>
#include <vector>
using namespace std;


class Test
{
    public:
    Test() { cout << "Test" << endl;}
    ~Test() { cout << "~Test" << endl;}

    private:
    Test(const Test &);
    void operator=(const Test &);
};

int main(int argc, char const *argv[])
{
    vector<UniquePtr<Test> > coll;

    // 此处push_back调用移动构造函数，在vector内构造一个UniquePtr<Test>接管右值的资源
    // 当vector出作用域时，会调用vector的析构函数
    // vector析构函数的作用：调用各成员析构函数来销毁成员（因此会调用智能指针的析构函数），再释放成员内存空间
    // 实际上delete完成的也是：调用析构函数销毁对象，然后释放对象内存空间
    coll.push_back(UniquePtr<Test>(new Test));
    return 0;
}

/*
Output:

Test
~Test

*/


