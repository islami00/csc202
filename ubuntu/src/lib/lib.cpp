#include "lib.h"

#include <iostream>

namespace my_utils {
int sum(int a, int b) {
  int c = a + b;
  return c;
}

char find_grades(int score) {
  if (score < 0 || score > 100) {
    return '\0';
  }
  char grade;
  switch (score / 10) {
    // By int division, equiv to score >= 90
    case 9:
      grade = 'A';
      break;
    // Score >= 80
    case 8:
      grade = 'B';
      break;
    // Score >= 70
    case 7:
      grade = 'C';
      break;
    // Score >= 60
    case 6:
      grade = 'D';
      break;
    // Score < 60
    default:
      grade = 'F';
      break;
  }
  return grade;
}

bool is_non_negative(int number) {
  if (number >= 0) {
    return true;
  }
  return false; 
};

// Stack::Stack() {
//   // Initialise stack by pointing end to the last element (0 cuz it's empty)
// }
// Stack::~Stack() {
//   // Delete stack
//   // Deallocate???
// }
// int Stack::push(int item) {
//   // Check if stack is full. No 4th el so the pointer
// }
// int Stack::pop() {
//   // Check if stack is empty
// }
// namespace my_utils
// Fix this.
// class Stack {
//  private:
//   /* data */
//   int length;
//   int st[4];            // Stack of 4
//   int *stEnd = &st[3];  // Pointer to end of stack

//  public:
//   Stack(){};
//   ~Stack(){};
//   int push(int item) {
//     // Check if exceeded end
//     if (stEnd == &st[3]) {
//       std::cout << "Pushing more than capacity";
//       throw "Pushing more than capacity";
//       return -1;
//     }
//     // Go forward
//     stEnd = stEnd + 1;
//     // Append to array.
//     *stEnd = item;
//     return 0;
//   }
//   int pop() {
//     // Check if at end
//     if (stEnd == &st[0]) {
//       std::cout << "Stack empty";
//       return -1;
//     }
//     // Get value
//     int item = *stEnd;
//     // Go back.
//     stEnd = stEnd - 1;
//     return item;
//   }
// };

}  // namespace my_utils
