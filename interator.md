# Iterator Design Pattern

The iterator allows a consumer to go over the elements of a collection without
knowing how the collection is implemented. 

The iterator pattern extracts out the responsibility of traversing over an
aggregate out of the aggregate's interface and encapsulates it in the iterator
class, thereby simplifying the aggregate's interface.

## Class Diagram

[Iterator Class Diagram](iterator_class_diagram.png)

## Example

Java already has an interface Iterator but for the purposes of learning, we'll
create it from scratch. Our interface will expose only two methods `next()`
and `hasNext()`. It'll look something like below:

```Java
public interface Iterator {

    void next();

    boolean hasNext();
}
```
Lets say we have a class `AirForce` and it contains different kinds of
aircraft, some are cargo airplanes, others are fighter jets and a few
helicopters. Objects for each of these aircraft types are stored in different
collection types. Take a minute to go over the `Airforce` class listing below:

```Java
public class AirForce {

    List<IAircraft> jets = new ArrayList<>();
    IAircraft[] helis = new IAircraft[1];
    LinkedList<Boeing747> cargo = new LinkedList<>();

    public List<IAircraft> getJets() {
        return jets;
    }

    public IAircraft[] getHelis() {
        return helis;
    }

    public LinkedList<Boeing747> getCargo() {
        return cargo;
    }

    public AirForce() {
        jets.add(new F16());
        helis[0] = new CobraGunship();
        cargo.add(new Boeing747());
    }

    // This method returns a concrete iterator that
    // traverses over the entire airforce planes.
    public Iterator createIterator() {
        return new AirForceIterator(this);

    }

    // This method returns a different concerete iterator
    // that traverses over only the jets in the airforce.
    public Iterator createJetsIterator() {
        return new JetsIterator(jets);

    }
}
```

Note the methods `createIterator()` and `createJetsIterator()` return objects
that implement the `Iterator` interface. Notice how each kind of aircraft is
stored in a different type of collection. If a client needs to list all the
aircraft in an airforce object, it'll have a hard time invoking getters and
then going over each individual collection. We mask this complexity by creating
an iterator class whose sole job is to list all the aircraft held by the
airforce. Look at the implementation below:

```Java
public class AirForceIterator implements Iterator {

    List<IAircraft> jets;
    IAircraft[] helis;
    LinkedList<Boeing747> cargo;
    int jetsPosition = 0;
    int helisPosition = 0;
    int cargoPosition = 0;

    /**
     * The iterator is composed with the object it'll be iterating over
     */
    public AirForceIterator(AirForce airForce) {
        jets = airForce.getJets();
        helis = airForce.getHelis();
        cargo = airForce.getCargo();

    }

    @Override
    /**
     * We provide our own custom logic of returning aircraft in a
     * sequence. Note we are returning IAircraft interface object which
     * every plane in our airforce implements. We also design the function
     * to throw a runtime exception if next is invoked when no more elements
     * are left to iterate over
     */
    public IAircraft next() {

        // return helis first
        if (helisPosition < helis.length) {
            return helis[helisPosition++];
        }

        // return jets second
        if (jetsPosition < jets.size()) {
            return jets.get(jetsPosition++);
        }

        // return cargos last
        if (cargoPosition < cargo.size()) {
            return cargo.get(cargoPosition++);
        }

        throw new RuntimeException("No more elements");

    }

    @Override
    public boolean hasNext() {

        return helis.length > helisPosition ||
               jets.size() > jetsPosition ||
               cargo.size() > cargoPosition;
    }
}
```

Let's look at how the client uses the iterator:
```Java
public class Client {

    public void main() {

        AirForce airForce = new AirForce();

        Iterator jets = airForce.createJetsIterator();

        while (jets.hasNext()) {
            jets.next();
        }

        Iterator allPlanes = airForce.createIterator();

        while (allPlanes.hasNext()) {
            allPlanes.next();
        }
    }
}
```

## Internal vs External Iterator

When the iteration control rests with the client using the iterator, that is,
the client is responsible for advancing the traversal and explicitly
requesting the next element from the iterator, it is an example of an external
iterator. Iterators in our aircraft example are external iterators. On the
other hand, when the client hands the iterator an operation to perform and the
iterator performs the operation on each element of the aggregate, it is an
example of an internal iterator.

