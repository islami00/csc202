#ifndef LIB_H
#define LIB_H
/**
 * Add two numbers
 *
 * */
int sum(int a, int b);

namespace my_utils {
/**
 * Example stack impl in cpp
 * */
class Stack {
  /* data */
  int length;
  int st[4];   // Stack of 4
  int *stEnd;  // Pointer to end of stack

 public:
  Stack();
  ~Stack();
  int push(int item);
  int pop();
};
}  // namespace my_utils

#endif  // !