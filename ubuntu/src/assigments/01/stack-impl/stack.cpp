#include <iostream>

#define STACK_SIZE 3
// We need a fixed size stack
class Stack {
 private:
  int top;
  //  It has fixed size
  int elements[STACK_SIZE];

 public:
  Stack();
  ~Stack();
  int pop();
  int peek();
  int push(int element);
  bool isEmpty();
  bool isFull();
  int change(int element, int position);
  void display();
};

Stack::Stack() { top = -1; }
Stack::~Stack() {}

//  It has methods
//   Pop allows us to take an element off the top
int Stack::pop() {
  if (isEmpty()) {
    throw std::logic_error("Trying to pop an empty stack");
  };
  int t = elements[top];
  elements[top] = 0;
  top = top - 1;
  return t;
}
//   peek allows us to check the topmost element
int Stack::peek() {
  if (isEmpty()) {
    throw std::logic_error("Trying to peek an empty stack");
    // return -1;
  };
  return elements[top];
}
//   Push allows us to put an element on the stack
int Stack::push(int element) {
  if (isFull()) {
    return -1;
  }
  top = top + 1;
  elements[top] = element;
  return 0;
}
//   Convenience methods
//   isEmpty
bool Stack::isEmpty() {
  if (top == -1) return true;
  return false;
}
//   isFull
bool Stack::isFull() {
  if ((top + 1) == STACK_SIZE) return true;
  return false;
}
//   display -- show all elements on the stack
void Stack::display() {
  for (size_t i = 0; i < STACK_SIZE; i++) {
    cout << "stack[" << i << "]"
         << " = " << elements[i] << '\n';
  }
}
//   Unnatural ---
//   change() -- Replace el at position
int Stack::change(int element, int position) {
  // 1. Underflow
  if (isEmpty()) return 1;

  // 2. Underflow
  if (position > top) return 2;
  //   proof: top>position >= 0;
  if (position < 0) return 3;

  // Else swap at pos.
  elements[position] = element;
  return 0;
}

// #[test]
// Little thingies about my stack:
// NEVER store 0 on the stack.
// Shift all values forward by one if you fear you'll encounter 0 to ensure your
// domain is strictly positive, because 0 is the default value.
#include <string>
using namespace std;
int test();
int main() { return test(); }

int menuTest() {
  //  create a switch-case menu for each stack method
}
int test() {
  Stack st1 = Stack();
  // peek
  bool peekWorks = false;
  try {
    st1.peek();
  } catch (const std::exception& e) {
    // Errs as required
    // std::cerr << e.what() << '\n';
    peekWorks = true;
  }
  if (!peekWorks) {
    throw std::logic_error("Peek didn't fail in empty state");
  }
  // isEmpty
  if (!st1.isEmpty()) {
    throw std::logic_error("isEmpty fails to recognize an empty stack");
  }
  // push
  int res1 = st1.push(1);
  int res2 = st1.push(2);
  int res3 = st1.push(3);
  bool pushWorks = !res1 && !res2 && !res3;  // all return 0;
  if (!pushWorks) {
    cout << "Individual push returns: " << res1 << " " << res2 << " " << res3
         << '\n';
    throw std::logic_error("Push is broken");
  }
  // isFull
  if (!st1.isFull()) {
    throw std::logic_error("isFull is broken in full state");
  }
  // pop
  int one, two, three;
  bool popWorks = false;
  try {
    one = st1.pop();
    two = st1.pop();
    three = st1.pop();
    st1.pop();
  } catch (const std::logic_error& e) {
    // Should throw at n. Hence, popWorks should be set to true. Only value
    // checks
    popWorks = (one == 1) && (two == 2) && (three == 3);
  }
  if (!st1.isEmpty()) {
    if (popWorks) cout << "Pop elements are being returned as expected";
    throw std::logic_error("pop is broken");
  }
  // change
  st1.push(1);
  st1.push(2);
  int n = st1.change(-1, 0);
  st1.pop();
  signed int minusOne = st1.pop();
  bool changeWorks = (minusOne == -1) && (n == 0);
  if (!changeWorks) {
    throw std::logic_error("Change is broken");
  }
  return 0;
}