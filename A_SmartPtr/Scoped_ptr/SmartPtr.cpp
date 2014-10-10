#include "SmartPtr.h"


SmartPtr::SmartPtr(Animal *ptr)
    :ptr_(ptr)
{
}

void SmartPtr::resetPtr(Animal *ptr)
{
    if(ptr != ptr_)
    {
        delete ptr_;
        ptr_ = ptr;
    }
}

