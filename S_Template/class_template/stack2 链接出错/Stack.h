#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <stdexcept>

template <typename T>
class Stack
{
public:
    void push(const T &t);
    void pop(); //出栈
    T top() const; //查看栈顶

    bool empty() const
    { return elems_.empty(); }

private:
    std::vector<T> elems_;
};




#endif /* STACK_H_ */