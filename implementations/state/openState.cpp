#include <iostream>

#include "openState.hpp"
#include "automaticDoor.hpp"

using namespace std;

void OpenState::timerExpired()
{
    cout << "Timer has expired, closing the door now" << endl;
    automaticDoor->setState(automaticDoor->getClosingState());
}

void OpenState::motionDetected()
{
    cout << "Door is open, resetting timer" << endl;
}
