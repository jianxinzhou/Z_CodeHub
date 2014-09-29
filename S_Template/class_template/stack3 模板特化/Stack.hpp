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

template <typename T>
void Stack<T>::push(const T &t)
{
    elems_.push_back(t);
}

template <typename T>
void Stack<T>::pop()
{
    if(elems_.empty())
        throw std::out_of_range("out_of_range");
    elems_.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
    if(elems_.empty())
        throw std::out_of_range("out_of_range");
    return elems_.back();
}



#endif /* STACK_H_ */