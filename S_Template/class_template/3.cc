#include <iostream>
#include <string>
#include <vector>
using namespace std;


//即使禁用了复制和赋值功能，编译也没有错误，因为主函数中没有调用push_back，因此模板并不会去实例化代码
class Test
{
    public:
        Test() { }
        ~Test() { }

    private:
        Test(const Test &);
        void operator=(const Test &);
};



int main(int argc, const char *argv[])
{
		// 此处仅仅实例化构造函数
    vector<Test> vec; 
    return 0;
}
