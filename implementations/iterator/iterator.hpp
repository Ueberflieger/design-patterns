#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

class Iterator{
    public:
    virtual int first() = 0;
    virtual int next() = 0;
    virtual bool hasNext() = 0;
};

#endif
