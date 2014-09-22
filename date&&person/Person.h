#ifndef PERSON_H
#define PERSON_H 

#include "Date.h"
#include <string>

class Person
{
    public:
        Person(const std::string &name, Date date);
        int howlongAlive() const;
        bool isCelebrated() const;
    private:
        std::string name_;
        Date birthday_;
};



#endif  /*PERSON_H*/
