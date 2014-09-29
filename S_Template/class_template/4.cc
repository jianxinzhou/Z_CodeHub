#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Test
{
    public:
        Test() { }
        ~Test() { }

    private:
        Test(const Test &);
        void operator=(const Test &);
};


//编译会报错，因为调用了push_back
int main(int argc, const char *argv[])
{
    vector<Test> vec; 
    Test t;
    vec.push_back(t);












    return 0;
}
