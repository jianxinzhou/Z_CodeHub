#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Parent;
class Child;

typedef shared_ptr<Parent> sParentPtr;
typedef shared_ptr<Child>  sChildPtr;
typedef weak_ptr<Parent>   wParentPtr;

class Parent
{
    public:
        // 析构函数，测试智能指针销毁时，是否delete了堆上的资源
        ~Parent() { cout << "~Parent" << endl; }
        
        // 数据成员为管理子类对象的shared_ptr<Child>
        sChildPtr sChild_;
};

class Child
{
    public:
        Child(const sParentPtr &parent)
            : wParent_(parent)
        { }
        
        ~Child(){ cout << "~Child" << endl; }

        // 数据成员为管理父类对象的weak_ptr<Parent>
        wParentPtr wParent_;
};

int main(int argc, const char *argv[])
{
    {
        sParentPtr parent(new Parent);
        sChildPtr  child(new Child(parent));
        parent->sChild_ = child;

        cout << "parent count: " << parent.use_count() << endl;
        cout << "child  count: " << child.use_count() << endl;
    }
    return 0;
}


/*
Output:

parent count: 1
child  count: 2
~Parent
~Child

*/
