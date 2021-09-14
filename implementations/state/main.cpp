#include "automaticDoor.hpp"

// Implementation of a automatic door with 4 states:
// closed, opening, open, closing
// The implementation makes use of the state design pattern

int main(void)
{
    AutomaticDoor door;

    door.personApproachesDoor();
    door.doorOpen();
    door.personApproachesDoor();
    door.openTimerExpired();
    door.doorClosed();

    return 0;
}
