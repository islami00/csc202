#include <iostream>

using namespace std;
#include <button.h>
int main() {
  //   using button to illustrate.
  button nth;
  nth.increase();
  nth.increase();
  {
    button test2;
    test2.increase();
    test2.increase();
    // What happens if I call destructor first??. Nothing happens. it still
    // continues. Can't call constructor because it is also the button name. If
    // you want privacy, make deconstructor private. You can't, just don't call
    // it before you need to. Here it's a console.log, else it could be
    // dealloc()
    test2.~button();
    test2.increase();
  }
  //   Test2 goes, nth remains
  nth.increase();
  return 0;
}