# Mediator Design Pattern

A mediator controls and coordinates the behavior for a group of objects. The
objects only communicate with the mediator or the director and don't know of
the other objects.

The mediator pattern should be applied when there are many objects
communicating in a well-structured but complex manner resulting in
interdependencies that are hard to understand. The participant objects in such
a scheme don't lend themselves for reuse because of dependence on so many other
objects.

Since the interaction rules or behavior is isolated in a single mediator class,
it becomes easier to change. Also note that in the absence of the mediator, the
objects are engaged in many-to-many interactions but when the mediator is
introduced the interactions become one-to-many between the mediator and the
other participating objects.

## Class Diagram

![Mediator Class Diagram](mediator_class_diagram.png)

## Example

Imagine an airport without an air-traffic control tower. All the airplanes in
flight, about to land and about to take-off need to be aware of every other
airplane to coordinate the use of the runways as well as the airspace. There
are in a sense dependent on each other to avoid a disaster but this leads to
having too many interconnections among objects. With a single runway, the
worst case is every airplane has to know about every other airplane about to
land or take-off to avoid collisions. The control tower object can act as a
mediator and communication hub for all the airplanes and ensure a smooth
working of the airport.

For instructional purposes, we'll implement the coordination logic required for
an airplane to land safely. The `ControlTower` class appears below:

```Java
public class ControlTower {

    List<IAircraft> queuedForLanding = new ArrayList<>();

    // An aircraft just notifies the control tower that it wants to
    // land and doesn't coordinate with other aircraft
    synchronized public void requestToLand(IAircraft aircraft) {
        queuedForLanding.add(aircraft);
    }

    public void run() {

        // perpetual loop
        while (true) {

            // inefficient busy wait till aircraft requests to land
            while(queuedForLanding.size() == 0);

            IAircraft aircraft;
            synchronized (this) {
                aircraft = queuedForLanding.remove(0);
            }
            // We have only one runway available so only allow a single
            // aircraft to land.
            aircraft.land();
        }
    }
}
```

The aircraft interface and classes are:

```Java
public interface IAircraft {

    public void land();
}

public class F16 implements IAircraft {

    ControlTower controlTower;

    public F16(ControlTower controlTower) {
        this.controlTower = controlTower;
    }

    @Override
    public void land() {
        System.out.println("F16 landing...");
    }

    public void requestControlTowerToLand() {
        controlTower.requestToLand(this);

    }
}
```

In our naive example the aircraft object communicates with the `ControlTower`
class and requests to land. The control tower object maintains a queue of
planes wishing to land and runs a perpetual thread-safe loop that allows each
plane to land one after the other. If the number of runways available increases
or close down for maintenance, the changes are localized to the ControlTower
class.

We used the control tower example also for the observer pattern and it applies
in the mediator pattern too as the interaction between the mediator and the
colleagues can be modeled on the observer pattern.
