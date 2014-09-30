#ifndef QUEUE_H_
#define QUEUE_H_

#include <deque>

template <typename T, typename V = std::deque<T> >
class Queue
{
public:
    typedef typename V::size_type size_type;


    void push(const T &t)
    {
        elems_.push_back(t);
    }
    void pop()
    {
        elems_.pop_front();
    }

    T &front() { return elems_.front(); }
    const T &front() const { return elems_.front(); }
    T &back() { return elems_.back(); }
    const T &back() const { return elems_.back(); }

    bool empty() const
    { return elems_.empty(); }

    size_type size() const
    { return elems_.size(); }
private:
    V elems_;
};


#endif  /* QUEUE_H_ */
