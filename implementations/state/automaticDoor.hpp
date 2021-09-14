#ifndef __AUTOMATICDOOR_H__
#define __AUTOMATICDOOR_H__

class AutomaticDoorState;

class AutomaticDoor
{
    private:
        AutomaticDoorState *currentState;
        AutomaticDoorState *closingState;
        AutomaticDoorState *closedState;
        AutomaticDoorState *openingState;
        AutomaticDoorState *openState;

    public:
        AutomaticDoor();
        void setState(AutomaticDoorState *newState);

        void personApproachesDoor();
        void openTimerExpired();
        void doorClosed();
        void doorOpen();

        AutomaticDoorState* getClosingState();
        AutomaticDoorState* getClosedState();
        AutomaticDoorState* getOpeningState();
        AutomaticDoorState* getOpenState();
};

#endif
