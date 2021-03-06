# design-patterns
educative.io design patterns notes

## Introduction

We use design patterns because we don't want to reinvent the wheel.

### Suggestion for OO design

1. Separate out parts of code that vary or change from those that remain the same.
1. Always code to an interface and not against a concrete implementation.
1. Encapsulate behaviors as much as possible.
1. Favor composition over inheritance. Inheritance can result in explosion of classes and also sometimes the base class is fitted with new functionality that isn't applicable to some of its derived classes.
1. Interacting components within a system should be as loosely coupled as possible.
1. Ideally, class design should inhibit modification and encourage extension.
1. Using patterns in your day to day work, allows exchanging entire implementation concepts with other developers via shared pattern vocabulary.

### Types of Design Patterns

There are three types of design patterns:

#### Creational

- [Builder Pattern](builder.md)
- [Singleton Pattern](singleton.md)
- [Prototype Pattern](prototype.md)
- [Factory Method Pattern](factory-method.md)
- [Abstract Factory Pattern](abstract-factory.md)

#### Structural

- [Adapter Pattern](adapter.md)
- [Bridge Pattern](bridge.md)
- [Composite Pattern](composite.md)
- [Decorator Pattern](decorator.md)
- [Facade Pattern](facade.md)
- [Flyweight Pattern](flyweight.md)
- [Proxy Pattern](proxy.md)

#### Behavioral

- [Chain of Responsibility Pattern](chain-of-responsibility.md)
- [Observer Pattern](observer.md)
- [Command Pattern](command.md)
- [Iterator Pattern](iterator.md)
- [Mediator Pattern](mediator.md)
- [Memento Pattern](memento.md)
- [State Pattern](state.md)
- [Strategy Pattern](strategy.md)
- [Visitor Pattern](visitor.md)
