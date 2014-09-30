#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <stddef.h>

template <typename T, size_t MAXSIZE>
class Array
{
public:
    typedef T value_type;
    typedef T *iterator;
    typedef const T * const_iterator;
    typedef T &reference;
    typedef const T &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    iterator begin()
    {
        return elems_;
    }
    const_iterator begin() const
    {
        return elems_;
    }
    iterator end()
    {
        return elems_ + MAXSIZE;
    }
    const_iterator end() const
    {
        return elems_ + MAXSIZE;
    }


    reference operator[](size_type index) 
    { 
        return elems_[index]; 
    }
    const_reference operator[] (size_type index) const
    {
        return elems_[index];
    }

    size_type size() const
    {
        return MAXSIZE;
    }

private:
    T elems_[MAXSIZE];
};



#endif /* ARRAY_HPP_ */