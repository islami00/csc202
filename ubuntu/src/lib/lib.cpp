#include "lib.h"

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
void prettyPrint(int arr[], size_t arr_size) {
  size_t lastIndex = arr_size - 1;
  for (size_t i = 0; i < arr_size; i++) {
    if (i == 0)
      std::cout << "[" << arr[i];
    else if (i == lastIndex)
      std::cout << "," << arr[i] << "]";
    else
      std::cout << "," << arr[i];
  }
}

bool arr_eq(int arr1[], int arr2[], int arr1_size, int arr2_size) {
  if (arr1_size != arr2_size) return false;
  bool eq = arr1[0] == arr2[0];
  for (int i = 0; (i < arr1_size) && eq; i++) {
    eq = eq && (arr1[i] == arr2[i]);
  }
  return eq;
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

}  // namespace my_utils
