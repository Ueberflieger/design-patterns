#include "closingState.hpp"
#include "automaticDoor.hpp"

void ClosingState::motionDetected()
{
    automaticDoor->setState(automaticDoor->getOpeningState());
}

void ClosingState::closedSignal()
{
    automaticDoor->setState(automaticDoor->getClosedState());
}
