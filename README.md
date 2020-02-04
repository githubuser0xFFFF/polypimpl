# A ploymorphic_value based PIMPL implementation
This code shows how to use the [polymorphic_value](https://github.com/jbcoe/polymorphic_value) type to implement the PIMPL idiom if polymorphism is involved. The big advantage of using `polymorphic_value` type for implementation of the internal private d pointer is its value semantics. That means, it is not required to implement special copy / move constructors or assignment operators in the public class - copying and moving simply works.

The macros that are declared in `poly_pimpl.h` are heavily inspired by the macros that are used in the Qt framework.

## Build
Just execute `qmake && make` in the source folder and run the application.
