#ifndef __OPENSTATE_H__
#define __OPENSTATE_H__

#include "automaticDoorState.hpp"

class OpenState: public AutomaticDoorState
{
    public:
        OpenState(AutomaticDoor *automaticDoor){this->automaticDoor = automaticDoor; stateStr = "Open";}
        void timerExpired();
        void motionDetected();
};

#endif
