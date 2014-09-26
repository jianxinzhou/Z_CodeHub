#ifndef STRING_H_
#define STRING_H_

#include <string.h>
#include <iostream>

class String
{
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);

    friend String operator+(const String &s1, const String &s2);
    friend String operator+(const String &s1, const char *s2);
    friend String operator+(const char *s1, const String &s2);

    friend bool operator<  (const String &s1, const String &s2);
    friend bool operator<= (const String &s1, const String &s2);
    friend bool operator>  (const String &s1, const String &s2);
    friend bool operator>= (const String &s1, const String &s2);
    friend bool operator== (const String &s1, const String &s2);
    friend bool operator!= (const String &s1, const String &s2);

public:

    String();
    String(const char *s); //const char * -> String 转化能力
    String(const String &s);
    ~String();

    String &operator=(const String &s);
    String &operator=(const char *s);
    String &operator+=(const String &s);
    String &operator+=(const char *s);

    void swap(String &other);

    char &operator[] (size_t index);
    char operator[] (size_t index) const; //s[i] = 'a';ERROR

    size_t size() const
    { return strlen(str_); }
    const char *c_str() const
    { return str_; }

    void debug() const;


    //String operator+(const String &s) const;
    //String operator+(const char *s) const;

private:
    char *str_;
};


// cout << s;  operator<<(cout, s)
inline std::ostream &operator<<(std::ostream &os, const String &s)
{
    return os << s.str_;
}

inline std::istream &operator>>(std::istream &is, String &s)
{
    char tmp[1024];
    if(is >> tmp)
        s = tmp;

    return is;
}


#endif /* STRING_H_ */
