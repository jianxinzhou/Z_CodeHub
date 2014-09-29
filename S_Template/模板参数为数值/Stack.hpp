#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <stdexcept>

template <typename T, int MAXSIZE>
class Stack
{
public:
    Stack();
    void push(const T &);
    void pop();
    T top() const;

    bool empty() const
    { return numElems_ == 0; }
    bool full() const
    { return numElems_ == MAXSIZE; }

private:
    T elems_[MAXSIZE];
    int numElems_;  //当前的元素数量
};

template <typename T, int MAXSIZE>
Stack<T, MAXSIZE>::Stack()
    :numElems_(0)
{

}

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(const T &elem)
{
    if(full())
        throw std::runtime_error("full");
    elems_[numElems_ ++] = elem;
}

template <typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
    if(empty())
        throw std::runtime_error("empty");
    --numElems_;
}

template <typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top() const
{
    return elems_[numElems_-1];
}


#endif /* STACK_H_ */