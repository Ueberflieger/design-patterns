#include <iostream>

using namespace std;

// Product interface
class Product{
     public:
         virtual ~Product(){}
         virtual void doSomething() = 0;
};

class ConcreteProductFoo1: public Product{
    public:
        void doSomething(){
            cout << "I am a Product Foo1" << endl;
        }
};

class ConcreteProductBar1: public Product{
    public:
        void doSomething(){
            cout << "I am a Product Bar1" << endl;
        }
};

class ConcreteProductFoo2: public Product{
    public:
        void doSomething(){
            cout << "I am a Product Foo2" << endl;
        }
};

class ConcreteProductBar2: public Product{
    public:
        void doSomething(){
            cout << "I am a Product Bar2" << endl;
        }
};

class Factory{
    public:
        virtual ~Factory(){}
        virtual Product *produceFoo() = 0;
        virtual Product *produceBar() = 0;
};

class ConcreteFactory1: public Factory{
    public:
        Product *produceFoo(){
            return new ConcreteProductFoo1() ;
        }
        
        Product *produceBar(){
            return new ConcreteProductBar1() ;
        }
};

class ConcreteFactory2: public Factory{
    public:
        Product *produceFoo(){
            return new ConcreteProductFoo2() ;
        }
        
        Product *produceBar(){
            return new ConcreteProductBar2() ;
        }
};

static void produceProducts(Factory *factory)
{
    factory->produceFoo()->doSomething();
    factory->produceBar()->doSomething();
}

int main(void)
{
    produceProducts(new ConcreteFactory1());
    produceProducts(new ConcreteFactory2());
}
