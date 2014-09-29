#include "Stack.hpp"
#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        Stack<int, 5> st;
        st.push(12); 
        st.push(23);
        st.push(45);
        st.push(56);
        st.push(43); 

        Stack<double, 10> st2;
        st2 = st;

        while(!st2.empty())
        {
            cout << st2.top() << endl;
            st2.pop();
        }
        

    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
