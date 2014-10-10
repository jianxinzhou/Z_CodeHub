#ifndef AUTOPTR_HPP
#define AUTOPTR_HPP 

#include <stddef.h> //NULL

template <typename T>
class AutoPtr
{
    public:
        typedef T element_type;
        typedef T *pointer;
        typedef T &reference;
        
        // 默认构造函数
        AutoPtr(element_type *ptr = NULL);
        // 拷贝构造函数
        AutoPtr(AutoPtr<T> &other);
        // 析构函数
        ~AutoPtr();
        
        // 赋值运算符
        AutoPtr<T> &operator=(AutoPtr<T> &other) throw();

        reference operator*()  const throw();
        pointer   operator->() const throw();

        void reset(pointer ptr = NULL) throw();
        pointer release() throw();

        operator bool();

    private:
        element_type *ptr_;
};

template <typename T>
AutoPtr<T>::AutoPtr(element_type *ptr)
    : ptr_(ptr)
{ }

template <typename T>
AutoPtr<T>::AutoPtr(AutoPtr<T> &other)
    : ptr_(other.release())
{ 
    // 所有权转移
}

template <typename T>
AutoPtr<T> &AutoPtr<T>::operator=(AutoPtr<T> &other) throw()
{
    // 将ptr从other中释放
    // 再交给自身
    reset(other.release());
    return *this;
}

template <typename T>
AutoPtr<T>::~AutoPtr()
{
    delete ptr_;
}

template <typename T>
typename AutoPtr<T>::reference AutoPtr<T>::operator*()  const throw()
{
    return *ptr_;
}

template <typename T>
typename AutoPtr<T>::pointer AutoPtr<T>::operator->() const throw()
{
    return ptr_;
}

template <typename T>
typename AutoPtr<T>::pointer AutoPtr<T>::release() throw()
{
    pointer tmp(ptr_);
    ptr_ = NULL;
    return tmp;
}

template <typename T>
void AutoPtr<T>::reset(pointer ptr) throw()
{
    if(ptr_ != ptr)
    {
        delete ptr_;
        ptr_ = ptr;
    }
}

template <typename T>
AutoPtr<T>::operator bool()
{
    return ptr_;
}


#endif  /*AUTOPTR_HPP*/
