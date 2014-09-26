#ifndef SMART_PTR_H_
#define SMART_PTR_H_

#include <iostream>

class Animal
{
public:

    Animal() { std::cout << "Animal" << std::endl; }
    ~Animal() { std::cout << "~Animal" << std::endl; }

    void run() { std::cout << "Animal is runing ...." << std::endl; }
};


class SmartPtr
{
public:
    SmartPtr(Animal *ptr = NULL);
    ~SmartPtr()
    { delete ptr_; }

    Animal &operator*()
    { return *ptr_; }
    const Animal &operator*() const
    { return *ptr_; }

    Animal *operator->()
    { return ptr_; }
    const Animal *operator->() const
    { return ptr_; }

    void resetPtr(Animal *ptr = NULL);
    const Animal *getPtr() const
    { return ptr_; }


private:
    SmartPtr(const SmartPtr &);
    void operator=(const SmartPtr &);

    Animal *ptr_;
};


#endif  /* SMART_PTR_H_ */
