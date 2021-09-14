#include <iostream>

#include "closedState.hpp"
#include "automaticDoor.hpp"

using namespace std;

void ClosedState::motionDetected()
{
    cout << "Motion detected, opening the door" << endl;
    automaticDoor->setState(automaticDoor->getOpeningState());
}
