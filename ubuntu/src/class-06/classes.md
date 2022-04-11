### Access rules.

1. `protected`: r but no w from outside
2. `private`: no r/w from outside, only within the class
3. `public`: r/w from outside.


## Objects and classes??

A class is a blueprint for an object.

How do we instantiate and use a class though?
E.g:Def:
```cpp
// <!-- Class: -->
class student{
    int grade;
}
```
* Instantiate.

```cpp
student x;
```
Student will hold all members witin student.
I.e, instead of `Array()`, just say `array x` and you have an empty array with all props and methods as in the class def.

No need for new keyword. **Note**: All members are private by default.
It's like how you can do `Array()` or `new Array()` in JS due to `call` and `construct` symbols on it.

### Internalise
Oh yeah. thinking about it like this, the constructor and destructors are then runtime hooks that get called right when a variable gets into scope and right before it is destroyed. The latter like the `drop` trait in rust.

### Initialising internals in constructor.
To avoid the issue of defining data in headers, we can simply use a constructor to initialise the data in it to avoid garbage values.

Types of constructors:
1. Default (no args).
2. Parameterized (takes in args)

Note:
You can use constructors implictly using : `className var(...args)`, or explicitly: `className var  = className(...args)`
So many ways lmao.

### Firend functions

functions being able to access private and protected members of a class. These are declared using the friend keyword inside the class declaration. 
you can define the functions with those access rights in place.