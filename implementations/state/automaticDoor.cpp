#include <iostream>

#include "automaticDoor.hpp"
#include "automaticDoorState.hpp"

#include "closingState.hpp"
#include "closedState.hpp"
#include "openingState.hpp"
#include "openState.hpp"

using namespace std;

AutomaticDoor::AutomaticDoor(){
    closingState = new ClosingState(this);
    closedState = new ClosedState(this);
    openingState = new OpeningState(this);
    openState = new OpenState(this);
    currentState = closedState;
    cout << "Automatic Door created, state: " << currentState->getStateStr() << endl; 
}

void AutomaticDoor::setState(AutomaticDoorState *newState){
    cout << "state: " << newState->getStateStr() << endl;
    currentState = newState;
}

void AutomaticDoor::personApproachesDoor(){
    currentState->motionDetected();
}

void AutomaticDoor::openTimerExpired(){
    currentState->timerExpired();
}

void AutomaticDoor::doorClosed(){
    currentState->closedSignal();
}

void AutomaticDoor::doorOpen(){
    currentState->openSignal();
}

AutomaticDoorState *AutomaticDoor::getClosingState(){
    return closingState;
}

AutomaticDoorState *AutomaticDoor::getClosedState(){
    return closedState;
}

AutomaticDoorState *AutomaticDoor::getOpeningState(){
    return openingState;
}

AutomaticDoorState *AutomaticDoor::getOpenState(){
    return openState;
}
