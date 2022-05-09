#include <iostream>
using namespace std;
class MyBase {
public:
  void show() // normal function
  {
    cout << "Base class show function called" << endl;
  }
  virtual void print() // virtual function
  {
    cout << " Base class print function called" << endl;
  }
};

class MyDerived : public MyBase {
public:
  void show() // normal function
  {
    cout << "Derived class show function called" << endl;
  }
  void print() // virtual function
  {
    cout << " Derived class print function called" << endl;
  }
};

int main() {
  //   MyBase *baseptr;
  //   MyDerived derivedobj;
  //   baseptr = &derivedobj;
  MyBase *baseptr = new MyDerived; // Equivalent
  // virtual function,binded at runtime
  baseptr->print();
  // non-virtual function, binded at compile time
  baseptr->show();
  return 0;
}