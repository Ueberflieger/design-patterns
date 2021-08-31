# Composite Design Pattern

The composite pattern lets us treat individual elements and group
of elements as one.

The closest analogy you can imagine is a tree (data structure).
The tree is a recursive data-structure where each part itself is
a sub-tree except for the leaf nodes. The root is the top-level
composite and its children are either composites themselves or
just leaf nodes. The leaf itself can be thought of as a tree with
just a single node.

The pattern allows the clients to ignore the differences between
the whole and the part.

## Class Diagram

![Composite Pattern Class Diagram](composite_pattern_class_diagram.png)

## Example

Assume, that we now want to represent all the aircraft in the combined
air forces of the NATO alliance. An air force is primarily made up of
several aircraft but it can also have sub-air forces. For instance,
the US has the 1st Air Force, 2nd Air Force so on and so forth. Our
NATO alliance can consist of air forces from multiple countries
including individual planes.

![Composite Pattern Example Tree Depiction](composite_pattern_example_tree_depiction.png)

The class `Airforce` will represent the composite and the other two
classes the part (leaf).

Each aircraft requires some number of pilots to operate and maybe
peripheral staff for maintainance. The classes would implement the
funtionality to return the number of personnel required for the aircraft
to operate. The Airforce class should return the total number of
personnel required to operate all the aircraft composed of the airforce.

```Java
public interface IAlliancePart {

    // Any implementing class should return the
    // the number of personnel or staff required
    // to operate the aircraft or the airfoce
    int getPersonnel();
}
```

The classes implementing the above interface appear below:
```Java
public class F16 implements IAircraft, IAlliancePart {

    @Override
    public int getPersonnel() {
        // We need 2 pilots for F-16
        return 2;
    }
}

public class C130Hercules implements IAircraft, IAlliancePart {

    @Override
    public int getPersonnel() {
        // This cargo plane, needs 5 people
        return 5;
    }
}
```
The above two classes act as parts, now we'll write the composite class
`Airforce`.

```Java
public class Airforce implements IAlliancePart {

    ArrayList<IAlliancePart> planes = new ArrayList<>();

    public void add(IAlliancePart alliancePart) {
        planes.add(alliancePart);
    }

    @Override
    public int getPersonnel() {

        // We iterator over the entire air force which can
        // contain leaf nodes (planes) or other composites
        // (air forces). This iteration is an example of an
        // internal iterator.
        Iterator<IAlliancePart> itr = planes.iterator();
        int staff = 0;

        while (itr.hasNext()) {
            staff += itr.next().getPersonnel();
        }

        return staff;
    }
}
```

The iterator will recursively call the getPersonnel method
on the nested air force objects. The leaves would actually be the planes
and will return a number. The personnel count for the root air force
object will be the sum of all the people required to operate all the
planes.

The client:
```Java
public class Client {

    public void main() {

        Airforce NatoAllaiance = new Airforce();
        
        // The nested methods aren't listed for brevity's sake
        NatoAllaiance.add(createCanadaAirForce());
        NatoAllaiance.add(createUSAAirForce());

        F16 frenchF16 = new F16();
        C130Hercules germanCargo = new C130Hercules();

        NatoAllaiance.add(frenchF16);
        NatoAllaiance.add(germanCargo);

        System.out.println(NatoAllaiance.getPersonnel());
    }
}
```

The client doesn't need to distinguish between the composite and the part.
To make this happen, the composite, as well as, the part needs to
implement a common interface or inherit from a common abstract class.
