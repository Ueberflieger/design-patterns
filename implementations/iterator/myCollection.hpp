#ifndef __MYCOLLECTION_HPP__
#define __MYCOLLECTION_HPP__

#include <vector>
#include "iterator.hpp"

using namespace std;

class MyCollection: Iterator
{
    private:
        vector<int> numbers;
        int current;
    
    public:
        MyCollection();
        Iterator* createIterator();
        void push(int val);
        int first();
        int next();
        bool hasNext();
};

#endif
