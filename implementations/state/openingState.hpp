#ifndef __OPENINGSTATE_H__
#define __OPENINGSTATE_H__

#include "automaticDoorState.hpp"

class OpeningState: public AutomaticDoorState
{
    public:
        OpeningState(AutomaticDoor *automaticDoor){this->automaticDoor = automaticDoor; stateStr = "Opening";}
        void openSignal();
};

#endif
