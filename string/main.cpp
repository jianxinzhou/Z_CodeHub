#include "String.h"
#include <iostream>
#include <assert.h>
using namespace std;


int main(int argc, char const *argv[])
{
    String s = "hello";

    // A a = 10;
    // A a(10);

    // vector<int> v(10);
    // vector<int> v = 10;

    s.debug();

    String s2(s);

    s.debug();

    String s3;
    s3 = s2;
    s3.debug();

    s3 = "foo";
    s3.debug();


    s3 += s2;

    s3.debug();

    s3 += "bar";
    s3.debug();

    cout << s3 << endl;

    // cin >> s;
    // cout << s << endl;


    String s4 = s + s3;
    cout << s4 << endl;

    s4 = s + "bar";
    cout << s4 << endl;

    s4 = "foo" + s;
    cout << s4 << endl;



    String t1 = "foobar";
    String t2 = "hello";

    assert(t1 < t2);
    assert(t2 > t1);
    assert(t1 <= t2);
    assert(t2 >= t1);

    assert(!(t1 == t2));
    assert(t1 != t2);

    s = "hello";
    cout << s[3] << endl;
    s[3] = 'A';
    cout << s << endl;

    const String s5 = "foo";
    //s5[1] = 'C';  //compile ERROR
    cout << s5 << endl;


    String k1 = "hello";
    String k2 = "world";
    k1.swap(k2);
    cout << k1 << endl;
    cout << k2 << endl;


    //std::swap(k1, k2);

    return 0;
}

