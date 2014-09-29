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
        st.push(7);   

        Stack<int, 10> st2;

        st = st2;

    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
