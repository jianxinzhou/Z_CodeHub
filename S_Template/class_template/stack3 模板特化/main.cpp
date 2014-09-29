#include "Stack.hpp"
#include <iostream>
#include <deque>
using namespace std;

template <> //模板特化
class Stack<string>
{
public:
    void push(const string &s)
    {
        elems_.push_back(s);
    }

    void pop()
    {
        elems_.pop_back();
    }

    string top() const
    {
        return elems_.back();
    }

    bool empty() const
    {
        return elems_.empty();
    }


private:
    std::deque<string> elems_;
};




int main(int argc, char const *argv[])
{
    try
    {
        // Stack<int> s1;
        // s1.push(7);

        // cout << s1.top() << endl;
        // s1.pop();

        // s1.pop(); //throw

        Stack<string> s;
        s.push("hello");

    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
