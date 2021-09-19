#include <iostream>

class MySingleton{
    public:
        static MySingleton& getInstance()
        {
            static MySingleton me;
            return me;
        }

        void doStuff(){
            std::cout << "YAYYY" << std::endl;
        }
    private:
        MySingleton(){}
        MySingleton(MySingleton const&);// Don't implement copy constructor
        void operator=(MySingleton const&); // Don't implement operator=
};

int main(void)
{
    MySingleton &singleton = MySingleton::getInstance();

    singleton.doStuff();

    return 0;
}
