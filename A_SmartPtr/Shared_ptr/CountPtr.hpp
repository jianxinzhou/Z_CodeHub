#ifndef COUNTER_HPP
#define COUNTER_HPP

template <typename T>
class CounterPtr
{
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;

        explicit CounterPtr(pointer ptr = NULL); //将内部的封装的指针默认初始化为NULL
        CounterPtr(const CounterPtr<T> &other);
        ~CounterPtr();

        CounterPtr<T> &operator=(const CounterPtr<T> &other);


        reference operator*()  const throw();
        pointer   operator->() const throw();
        

        size_t  count()  const throw(); // 返回当前引用计数
        pointer get()    const throw(); // 返回内部指针
        bool    unique() const throw(); // 测试引用计数是否为1
        operator bool();                // 使对象可以直接被if语句所用

        void swap(CounterPtr<T> &other) throw(); 
        void reset(pointer ptr = NULL) throw();




    private:

        void dispose(); // 用于处理析构函数和赋值运算符

        T *ptr_;        // 用于管理T类型对象的指针
        size_t *count_; // 引用计数
};





template <typename T>
void CounterPtr<T>::dispose()
{
    if(--*count_ == 0)
    {
        delete ptr_;
        delete count_;
    }
}

// 构造函数
template <typename T>
CounterPtr<T>::CounterPtr(pointer ptr)
    :ptr_(ptr), count_(new size_t(1))
{ }

// 拷贝构造函数
template <typename T>
CounterPtr<T>::CounterPtr(const CounterPtr<T> &other)
    :ptr_(other.ptr_), count_(other.count_)
{
    ++*count_; // 引用计数+1  
}

// 析构函数
template <typename T>
CounterPtr<T>::~CounterPtr()
{
    dispose();
}

// 赋值运算符
template <typename T>
CounterPtr<T> &CounterPtr<T>::operator=(const CounterPtr<T> &other)
{
    if(this != &other)
    {
        dispose();
        ptr_   = other.ptr_;
        count_ = other.count_;
        ++*count_;
    }
    return *this;
   
    /*等价实现如下：
    ++*other.count_;   // 先对other进行+1，这样不用处理自赋值
    dispose();
    ptr_   = other.ptr_;
    count_ = other.count_;
    return *this;
        
    */
}


template <typename T>
inline typename CounterPtr<T>::reference CounterPtr<T>::operator*() const throw()
{
    return *ptr_;
}

template <typename T>
inline typename CounterPtr<T>::pointer CounterPtr<T>::operator->() const throw()
{
    return ptr_;
}

template <typename T>
inline size_t CounterPtr<T>::count() const throw()
{
    return *count_;
}

template <typename T>
inline typename CounterPtr<T>::pointer CounterPtr<T>::get() const throw()
{
    return ptr_;
}

template <typename T>
inline bool CounterPtr<T>::unique() const throw()
{
    return *count_ == 1;
}

template <typename T>
inline CounterPtr<T>::operator bool()
{
    return ptr_;
}

template <typename T>
void CounterPtr<T>::swap(CounterPtr<T> &other) throw()
{
    std::swap(ptr_, other.ptr_);
    std::swap(count_, other.count_);
}

template <typename T>
void CounterPtr<T>::reset(pointer ptr) throw()
{
    dispose();
    ptr_ = ptr;
    count_ = new size_t(1);
}



#endif  /*COUNTER_HPP*/
