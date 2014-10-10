#ifndef SCOPED_PTR_HPP_
#define SCOPED_PTR_HPP_ 

#include <stddef.h>

template <typename T>
class ScopedPtr
{
    public:
        typedef T element_type;
        typedef T *pointer;
        typedef T &reference;

        // 默认构造函数
        ScopedPtr(pointer ptr = NULL) throw();
        // 析构函数
        ~ScopedPtr() throw();

        reference operator*()  const throw();
        pointer   operator->() const throw();
        
        pointer get() const throw(); // 获取原始指针
        void reset(pointer ptr = NULL) throw();
    private:
        // 禁用复制和赋值
        ScopedPtr(const ScopedPtr &);
        void operator=(const ScopedPtr &);

        pointer ptr_;
};


// 默认构造函数
template <typename T>
ScopedPtr<T>::ScopedPtr(pointer ptr) throw()
    : ptr_(ptr)
{ }

// 析构函数
template <typename T>
ScopedPtr<T>::~ScopedPtr() throw()
{
    delete ptr_;
}

template <typename T>
typename ScopedPtr<T>::reference
ScopedPtr<T>::operator*() const throw()
{
    return *ptr_;
}

template <typename T>
typename ScopedPtr<T>::pointer
ScopedPtr<T>::operator->() const throw()
{
    return ptr_;
}

template <typename T>
typename ScopedPtr<T>::pointer
ScopedPtr<T>::get() const throw()
{
    return ptr_;
}

template <typename T>
void ScopedPtr<T>::reset(pointer ptr) throw()
{
    if(ptr_ != ptr)
    {
        delete ptr_;
        ptr_ = ptr;
    }
}
#endif  /*SCOPED_PTR_HPP_*/
