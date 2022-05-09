#include <iostream>
using namespace std;
class Base {
public:
  virtual void show() { cout << "Base class\n"; }
};
class Derived : public Base {
private:
  // This is private on A
  virtual void show() { cout << "Derived class\n"; }
};
int main() {
  Base *a;
  a = new Derived;
  a->show(); // This stiill calls derived. Due to late binding and we're already
             // allowed to call it at compile time
}