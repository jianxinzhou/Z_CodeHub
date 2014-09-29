#include "Stack.h"


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
