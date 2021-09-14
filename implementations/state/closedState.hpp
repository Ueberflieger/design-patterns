#ifndef __CLOSEDSTATE_H__
#define __CLOSEDSTATE_H__

#include "automaticDoorState.hpp"

class ClosedState: public AutomaticDoorState
{
    public:
        ClosedState(AutomaticDoor *automaticDoor){this->automaticDoor = automaticDoor; stateStr = "Closed";}
        void motionDetected();
};

#endif
