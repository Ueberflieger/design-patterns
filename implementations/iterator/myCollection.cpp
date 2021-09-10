#include <vector>

#include "iterator.hpp"
#include "myCollection.hpp"

using namespace std;

MyCollection::MyCollection()
{
}

void MyCollection::push(int val)
{
    this->numbers.push_back(val);
}

int MyCollection::first()
{
    current = 0;
    return numbers[current];
}

int MyCollection::next()
{
    if (current < numbers.size() - 1)
    {
        current++;
    }
    
    return numbers[current];
}

bool MyCollection::hasNext()
{
    if (current < numbers.size() - 1)
    {
        return true;
    }
    return false;
}
