#include "openingState.hpp"
#include "automaticDoor.hpp"

void OpeningState::openSignal()
{
    automaticDoor->setState(automaticDoor->getOpenState());
}
