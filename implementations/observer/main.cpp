#include <iostream>
#include <vector>

using namespace std;

class Subscriber{
    public:
        virtual ~Subscriber(){};
        virtual void notify(int news) = 0;
};

class Observer : public Subscriber{
    public:
        void notify(int news){
            cout << "thanks got the news: " << news << endl;;
        }
};

class Observable{
    public:
    virtual ~Observable(){};
    virtual void subscribe(Subscriber &subscriber) = 0;
};

class Subject : public Observable{

    private:
        int bloodyInteresingInfo;
        vector<Subscriber*> subscribers;

    public:
        void subscribe(Subscriber &subscriber){
            cout << "got a new subscriber" << endl;
            subscribers.push_back(&subscriber);
        }

        void updateInfo(int info){
            bloodyInteresingInfo = info;
            for (auto subscriber:subscribers){
                subscriber->notify(bloodyInteresingInfo);
            }
        }
};

int main(void)
{
    Subject subject;
    Observer observer;

    subject.subscribe(observer);

    subject.updateInfo(3);

    return 0;
}
