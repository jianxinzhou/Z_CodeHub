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


    template <typename T2, int MAXSIZE2>
    Stack<T, MAXSIZE> &operator=(const Stack<T2, MAXSIZE2> &other); 

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

//st = st2;

template <typename T, int MAXSIZE>
template <typename T2, int MAXSIZE2>
Stack<T, MAXSIZE> &Stack<T, MAXSIZE>::operator=(const Stack<T2, MAXSIZE2> &other)
{
    if((void*)this == (void*)&other)
        return *this;

    numElems_ = 0;
    Stack<T2, MAXSIZE2> temp(other); //产生一个other的拷贝

    while(!temp.empty())
    {
        push(temp.top());
        temp.pop();
    }

    return *this;
}

#endif /* STACK_H_ */