#include "Integer.h"

using namespace std;


Integer::Integer(int data)
    :data_(data)
{
}

ostream &operator<< (ostream &os, const Integer &i)
{
    return os << i.data_;
}

istream &operator>> (istream &is, Integer &i)
{
    int temp = i.data_;  //backup; 
    is >> i.data_;
    if(!is) //输入失败
    {
        i.data_ = temp; //还原
    }
        
    return is;
}


Integer &Integer::operator++()
{
    //++i = 5;
    ++data_;

    return *this;
}

Integer Integer::operator++(int)
{
    //i++ 不能为左值
    Integer temp(*this);  //备份old
    ++data_;

    return temp;
}

Integer &Integer::operator=(int data)
{
    data_ = data;
    return *this;
}

