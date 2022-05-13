#include <lib.h>

#include <iostream>
// #[test]
// Stack test:
using namespace std;
int test();
int getChoice();
int menuTest();
int main() { return test(); }

int menuTest() {
  // Get choice and run stack methods based on it
  int choice;
  my_utils::Stack s;
  while (choice != 7) {
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
        try {
          int t = s.peek();
          cout << "The topmost element is: " << t << endl;
        } catch (std::logic_error& e) {
          cout << "Exception: " << e.what() << endl;
        }
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
      case 4:
        s.display();
        break;
      case 5:
        if (s.isEmpty()) {
          cout << "Stack is empty" << endl;
        } else {
          cout << "Stack is not empty" << endl;
        }
        break;
      case 6:
        if (s.isFull()) {
          cout << "Stack is full" << endl;
        } else {
          cout << "Stack is not full" << endl;
        }
        break;
      case 7:
        cout << "Exiting..." << endl;
        break;
    }
  }
  return 0;
}
int getChoice() {
  // Switch-case menu for each stack method
  int choice;
  cout << "1. Push" << endl;
  cout << "2. Peek" << endl;
  cout << "3. Pop" << endl;
  cout << "4. Display" << endl;
  cout << "5. isEmpty" << endl;
  cout << "6. isFull" << endl;
  cout << "7. Exit" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  return choice;
}
int test() {
  my_utils::Stack st1 = my_utils::Stack();
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
  int res4 = st1.push(3);

  bool pushWorks =
      !res1 && !res2 && !res3 && (res4 == 1);  // all return 0, and last errs;
  if (!pushWorks) {
    cout << "Individual push returns: " << res1 << ", " << res2 << ", " << res3
         << ", " << res4 << '\n';
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
  return 0;
}