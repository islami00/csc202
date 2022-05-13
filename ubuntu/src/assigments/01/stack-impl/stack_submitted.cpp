#include <iostream>

#define STACK_SIZE 3
// We need a fixed size stack
class Stack {
 private:
  signed int top;
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
    return 1;
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
  if (top == -1) {
    std::cout << "Stack is empty" << std::endl;
    return;
  }
  std::cout << "Stack: " << std::endl;
  for (int i = 0; i <= top; i++) {
    std::cout << "stack[" << i << "]"
              << " = " << elements[i] << '\n';
  }
}
//   Unnatural ---
//   change() -- Replace el at position
int Stack::change(int element, int position) {
  // 1. Underflow
  if (isEmpty()) return 1;

  // 2. Overflow
  if (position > top) return 2;
  //   Invariant for swap: top > position >= 0;
  if (position < 0) return 3;

  // Else swap at pos.
  elements[position] = element;
  return 0;
}

// #[test]
// Stack test:
using namespace std;
int test();
int getChoice();
int menuTest();
int main() { return menuTest(); }

int menuTest() {
  // Get choice and run stack methods based on it
  int choice;
  Stack s;
  while (choice != 8) {
    choice = getChoice();
    switch (choice) {
      case 1: {
        cout << "Enter the element to push onto the stack" << endl;
        int element;
        cin >> element;
        signed int r = s.push(element);
        if (r == 1) {
          cout << "Error: Stack is full" << endl;
        }
        s.display();
        break;
      }
      case 2:
        cout << "The topmost element is: " << s.peek() << endl;
        break;
      case 3:
        try {
          int el = s.pop();
          cout << "The element popped is: " << el << endl;
          s.display();
        } catch (const std::exception& e) {
          std::cerr << "Exception: " << e.what() << '\n';
        }
        break;
      case 4: {
        cout << "Enter the element to change with on the stack" << endl;
        int element2;
        cin >> element2;
        cout << "Enter the position to change with on the stack" << endl;
        int position;
        cin >> position;
        int stackChangeExitCode = s.change(element2, position);
        if (stackChangeExitCode == 0) {
          cout << "Element changed" << endl;
        } else if (stackChangeExitCode == 1) {
          cout << "Error: Underflow" << endl;
        } else if (stackChangeExitCode == 2) {
          cout << "Error: Overflow" << endl;
        } else if (stackChangeExitCode == 3) {
          cout << "Error: Invalid position" << endl;
        }
        s.display();
        break;
      }
      case 5:
        s.display();
        break;
      case 6:
        if (s.isEmpty()) {
          cout << "Stack is empty" << endl;
        } else {
          cout << "Stack is not empty" << endl;
        }
        break;
      case 7:
        if (s.isFull()) {
          cout << "Stack is full" << endl;
        } else {
          cout << "Stack is not full" << endl;
        }
        break;
      case 8:
        cout << "Exiting..." << endl;
        break;
    }
  }
}
int getChoice() {
  // Switch-case menu for each stack method
  int choice;
  cout << "1. Push" << endl;
  cout << "2. Peek" << endl;
  cout << "3. Pop" << endl;
  cout << "4. Change" << endl;
  cout << "5. Display" << endl;
  cout << "6. Exit" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}