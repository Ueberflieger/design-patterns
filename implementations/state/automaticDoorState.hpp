#ifndef __AUTOMATICDOORSTATE_H__
#define __AUTOMATICDOORSTATE_H__

#include <string>

class AutomaticDoor;

class AutomaticDoorState
{
    protected:
        std::string stateStr;
        AutomaticDoor *automaticDoor;

    public:
        AutomaticDoorState(){}
        std::string getStateStr(){return stateStr;};
        virtual void motionDetected(){}
        virtual void openSignal(){}
        virtual void closedSignal(){}
        virtual void timerExpired(){}
};

#endif
