#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <stdexcept>

//缺省的模板参数
template <typename T, typename CONT = std::vector<T> >
class Stack
{
public:
    void push(const T &t);
    void pop(); //出栈
    T top() const; //查看栈顶

    bool empty() const
    { return elems_.empty(); }

private:
    CONT elems_;
};

template <typename T, typename CONT>
void Stack<T, CONT>::push(const T &t)
{
    elems_.push_back(t);
}

template <typename T, typename CONT>
void Stack<T, CONT>::pop()
{
    if(elems_.empty())
        throw std::out_of_range("out_of_range");
    elems_.pop_back();
}

template <typename T, typename CONT>
T Stack<T, CONT>::top() const
{
    if(elems_.empty())
        throw std::out_of_range("out_of_range");
    return elems_.back();
}



#endif /* STACK_H_ */