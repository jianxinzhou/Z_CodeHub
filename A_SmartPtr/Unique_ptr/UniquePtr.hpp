#ifndef UNIQUE_HPP_
#define UNIQUE_HPP_ 

#include <algorithm>

template <typename T>
class UniquePtr
{
    public:
        typedef T element_type;
        typedef T *pointer;
        typedef T &reference;

        // 默认构造函数
        explicit UniquePtr(pointer ptr = NULL) throw();
        // 移动构造函数
        UniquePtr(UniquePtr &&) throw();
        // 移动赋值运算符
        UniquePtr &operator=(UniquePtr &&) throw();
        // 析构函数
        ~UniquePtr() throw();

        reference operator*()  const throw();
        pointer   operator->() const throw();

        pointer get() const throw(); // 获取原始指针
        void swap(UniquePtr &other);  

        pointer release() throw();
        void reset(pointer ptr = NULL) throw();

    private:
        // 禁用复制和赋值
        UniquePtr(const UniquePtr &);
        void operator=(const UniquePtr &);
        // 内部封装指针ptr_来管理资源
        pointer ptr_;
};

// 默认构造函数
template <typename T>
inline UniquePtr<T>::UniquePtr(pointer ptr) throw()
    : ptr_(ptr)
{ }

// 移动构造函数
template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr &&u) throw()
    : ptr_(u.ptr_)
{ 
    u.ptr_ = NULL; 
}

// 移动赋值运算符
template <typename T>
UniquePtr<T> &UniquePtr<T>::operator=(UniquePtr &&u) throw()
{
    if(this != &u)
    {
        delete ptr_;
        ptr_   = u.ptr_;
        u.ptr_ = NULL;
    }
    return *this;
}

// 析构函数
template <typename T>
UniquePtr<T>::~UniquePtr() throw()
{
    delete ptr_;
}

template <typename T>
typename UniquePtr<T>::reference 
UniquePtr<T>::operator*() const throw()
{
    return *ptr_;
}

template <typename T>
typename UniquePtr<T>::pointer
UniquePtr<T>::operator->() const throw()
{
    return ptr_;
}

template <typename T>
typename UniquePtr<T>::pointer
UniquePtr<T>::get() const throw()
{
    return ptr_;
}

template <typename T>
void UniquePtr<T>::swap(UniquePtr &other)
{
    std::swap(ptr_, other.ptr_);
}

template <typename T>
typename UniquePtr<T>::pointer
UniquePtr<T>::release() throw()
{
    pointer tmp(ptr_);
    ptr_ = NULL;
    return tmp;
}

template <typename T>
void UniquePtr<T>::reset(pointer ptr) throw()
{
    if(ptr_ != ptr)
    {
        delete ptr_;
        ptr_ = ptr;
    }
}




#endif  /*UNIQUE_HPP_*/
