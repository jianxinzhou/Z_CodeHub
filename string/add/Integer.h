#ifndef INTEGER_H_
#define INTEGER_H_

#include <iostream>

class Integer
{

    friend std::ostream &operator<< (std::ostream &os, const Integer &i);
    friend std::istream &operator>> (std::istream &is, Integer &i);

public:
    Integer(int data = 0);  // int -> Integer
    Integer &operator=(int data);

    Integer &operator++(); //++i
    Integer operator++(int); //i++

    operator int() //类型转化
    { return data_; }

private:
    int data_;
};


#endif /* INTEGER_H_ */

