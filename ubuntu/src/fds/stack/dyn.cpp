#define OVERFLOW -1
#define UNDERFLOW -2
#include <iostream>

#include "islgr_util.h"
#include "lib.h"
class DynS {
 private:
  int top;
  int STACK_MAX;
  // flexible members must be at end of class
  int* items;

 public:
  DynS(int size);
  ~DynS();
  //   core
  int push(int data);
  int pop();
  int peek();
  //   conv.
  bool isEmpty();
  bool isFull();
  int count();
  void display();
};

void tests();

int main() {
  tests();
  return 0;
}
// Class
DynS::DynS(int len) {
  // simple impl allows specifying size. Can use linked list for more
  // flexibility.
  STACK_MAX = len;
  top = -1;
  items = new int[len];
}
DynS::~DynS() { delete[] items; }
bool DynS::isEmpty() { return top == -1; }
bool DynS::isFull() { return count() == STACK_MAX; }
int DynS::count() { return top + 1; }
int DynS::peek() {
  if (isEmpty()) return UNDERFLOW;
  return items[top];
}
int DynS::push(int data) {
  if (isFull()) {
    return OVERFLOW;
  }
  top = top + 1;
  items[top] = data;
  return 0;
}
int DynS::pop() {
  if (isEmpty()) {
    return UNDERFLOW;
  }
  // remove and clear.
  int last = items[top];
  items[top] = 0;
  top -= 1;
  return last;
}
void DynS::display() {
  if (isEmpty()) {
    std::cout << "Stack is empty" << std::endl;
    return;
  }
  my_utils::prettyPrint(items, count());
  std::cout << std::endl;
}
// fxs
void tests() {
  int STACK_MAX = 9;
  DynS* s = new DynS(STACK_MAX);
  s->display();
  EXPECT_T(s->isEmpty());
  EXPECT_T(s->count() == 0);
  // push!, peek!
  s->push(12);
  EXPECT_T(s->peek() == 12);
  s->display();
  // pop!
  EXPECT_T(s->pop() == 12);
  EXPECT_T(s->peek() == UNDERFLOW);
  EXPECT_T(s->pop() == UNDERFLOW);
  //   fill and isFull
  for (int i = 0; i < STACK_MAX; i++) {
    s->push(i + 1);
  }
  EXPECT_T(s->isFull());
  EXPECT_T(s->peek() == STACK_MAX);
  s->display();
}
