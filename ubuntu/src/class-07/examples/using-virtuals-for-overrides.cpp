//! This example uses virtuals and overrides to perform specialisation-type
//! inheritance on the same method. (I seem to recall something similar with
//! jeff on fireshipio)
#include <iostream>
using namespace std;

class Animal {
public:
  virtual void eat() { cout << "I'm eating generic food\n"; }
};

class Cat : public Animal {
public:
  void eat() { cout << "I'm eating cat food\n"; }
};

class Dog : public Animal {
public:
  void eat() { cout << "I'm eating Dog food"; }
};

// This calls the eat method on an animal
void callEat(Animal *animalIsh) { animalIsh->eat(); }

int main() {
  Animal *ptr;
  //   Cat catobj;
  //   Dog dogobj;
  ptr = new Cat; // Equivalent
  callEat(ptr); // Calls the eat of cat
  ptr = new Dog; // Equivalent to passing a ref
  callEat(ptr); // Calls the eat of dog
}