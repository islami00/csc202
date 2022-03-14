#include "lib.h"

#include <iostream>
int sum(int a, int b) {
  int c = a + b;
  return c;
}

namespace my_utils {

class Stack {
 private:
  /* data */
  int length;
  int st[4];            // Stack of 4
  int *stEnd = &st[3];  // Pointer to end of stack

 public:
  Stack(){};
  ~Stack(){};
  int push(int item) {
    // Check if exceeded end
    if (stEnd == &st[3]) {
      std::cout << "Pushing more than capacity";
      throw "Pushing more than capacity";
      return -1;
    }
    // Go forward
    stEnd = stEnd + 1;
    // Append to array.
    *stEnd = item;
    return 0;
  }
  int pop() {
    // Check if at end
    if (stEnd == &st[0]) {
      std::cout << "Stack empty";
      return -1;
    }
    // Get value
    int item = *stEnd;
    // Go back.
    stEnd = stEnd - 1;
    return item;
  }
};

}  // namespace my_utils
