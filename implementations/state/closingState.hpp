#ifndef __CLOSINGSTATE_H__
#define __CLOSINGSTATE_H__

#include "automaticDoorState.hpp"

class ClosingState: public AutomaticDoorState
{
    public:
        ClosingState(AutomaticDoor *automaticDoor){this->automaticDoor = automaticDoor; stateStr = "Closing";}
        void motionDetected();
        void closedSignal();
};

#endif
