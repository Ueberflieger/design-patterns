#include <iostream>

#include "iterator.hpp"
#include "myCollection.hpp"

using namespace std;

int main(void)
{
    MyCollection myCollection;
    Iterator *iter;

    myCollection.push(1);
    myCollection.push(3);
    myCollection.push(2);

    cout << myCollection.first() << endl;
    while(myCollection.hasNext())
    {
        cout << myCollection.next() << endl;
    }
}
