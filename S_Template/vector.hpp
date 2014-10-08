#ifndef VECTOR_HPP
 
#define VECTOR_HPP
 

#include <memory>
 
#include <stddef.h>
 

template <typename T, typename Alloc = std::allocator<T> >
 
class Vector
 
{
 
public:
 
    typedef T value_type;
 
    typedef T *iterator;
 
    typedef const T * const_iterator;
 
    typedef T &reference;
 
    typedef const T &const_reference;
 
    typedef size_t size_type;
 
    typedef ptrdiff_t difference_type;
 
    typedef Alloc allocator_type;
 

    Vector() { create(); }
 
    Vector(size_type n, const T &val = T()) 
    { create(n, val); }
 

    template <typename In>
 
    Vector(In i, In j) //һ�ε�����ȥ��ʼ������
 
    {
 
        create(i, j);
 
    }
 

    Vector(const Vector &v)
 
    { create(v.begin(), v.end()); }
 
    Vector &operator=(const Vector &v);
 
    ~Vector() { uncreate(); }
 

    reference operator[] (size_type n) { return data_[n]; }
 
    const_reference operator[] (size_type n) const { return data_[n]; }
 

    void push_back(const T &t);
 

    void swap(Vector &other)
 
    {
 
        std::swap(data_, other.data_);
 
        std::swap(avail_, other.avail_);
 
        std::swap(limit_, other.limit_);
 
    }
 


    size_type size() const { return avail_ - data_; }
 
    size_type capacity() const { return limit_ - data_; }
 

    iterator begin() { return data_; }
 
    iterator end() { return avail_; }
 
    const_iterator begin() const { return data_; }
 
    const_iterator end() const { return avail_; }
 

    allocator_type get_allocator() const
 
    { return alloc_; }
 

private:
 
    iterator data_; //�������Ԫ��
 
    iterator avail_; //���һ��Ԫ�ص���һ��λ��
 
    iterator limit_; //���һ���ڴ����һ��λ��
 

    std::allocator<T> alloc_; //�ڴ������
 

    //Ϊ�ײ�����鿪���ڴ�ռ䣬��ִ����Ӧ�ĳ�ʼ��
 
    void create();
 
    void create(size_type, const T &);
 
    template <typename In>
 
    void create(In, In);
 

    //ɾ�������е�Ԫ�أ������ͷ��ڴ�
 
    void uncreate();
 

    //����push_back����
 
    void grow();
 
    void unCheckedAppend(const T &);
 
};
 


template <typename T, typename Alloc>
 
void Vector<T, Alloc>::push_back(const T &t)
 
{
 
    if(avail_ == limit_) // full
 
        grow();
 
    unCheckedAppend(t);
 
}
 

template <typename T, typename Alloc>
 
void Vector<T, Alloc>::create()
 
{
 
    data_ = avail_ = limit_ = NULL;
 
}
 

template <typename T, typename Alloc>
 
void Vector<T, Alloc>::create(size_type n, const T &val)
 
{
 
    //�����ڴ�
 
    data_ = alloc_.allocate(n);
 
    //ִ�й��캯�� �������캯��
 
    std::uninitialized_fill(data_, data_ + n, val);
 
    avail_ = limit_ = data_ + n;
 

    //Ϊʲô������new��
 
}
 


template <typename T, typename Alloc>
 
template <typename In>
 
void Vector<T, Alloc>::create(In i, In j)
 
{
 
    //�����ڴ�
 
    data_ = alloc_.allocate(j-i);
 
    //ִ�й��캯�� copy
 
    avail_ = limit_ = std::uninitialized_copy(i, j, data_);
 
}
 

template <typename T, typename Alloc>
 
void Vector<T, Alloc>::uncreate()
 
{
 
    //��ִ����������
 

    if(data_)
 
    {
 
        iterator it(avail_); //��ʼ
 
        while(it != data_)
 
            alloc_.destroy(--it);
 
    }
 

    //�ͷ��ڴ�
 
    alloc_.deallocate(data_, limit_ - data_);
 

    data_ = limit_ = avail_ = NULL;
 
}
 

template <typename T, typename Alloc>
 
void Vector<T, Alloc>::grow()
 
{
 
    //ȷ��size
 
    size_type current_size = limit_ - data_; //��ǰ��С
 
    size_type new_size = (current_size*2 > 1) ?  current_size*2 : 1;
 

    //�����ڴ沢����
 
    iterator new_data = alloc_.allocate(new_size);
 
    iterator new_avail =  uninitialized_copy(data_, avail_, new_data);
 

    //�ͷ�ԭ����Ԫ��
 
    uncreate();
 

    //����ָ��
 
    data_ = new_data;
 
    avail_ = new_avail;
 
    limit_ = data_ + new_size;
 
}
 

template <typename T, typename Alloc>
 
void Vector<T, Alloc>::unCheckedAppend(const T &val)
 
{
 
    alloc_.construct(avail_++, val); //�����µ�Ԫ��
 
}
 



#endif  /* VECTOR_HPP */