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
    if (i == 0) {
      std::cout << "[" << arr[i];
      if (i == arr_size - 1) {
        std::cout << "]";
      }
    } else if (i == lastIndex)
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
int deleteAtIndex(int arr[], int* UB, int index, const int LB, const int MAX) {
  if ((*UB) == LB) return 1;                    // Underflow
  if ((index < LB) || (index > MAX)) return 2;  // Out of bounds

  // Delete logic
  // 1. Clear position
  arr[index] = 0;
  // 2. Move every element backwards by one place to fill space
  int k = index + 1;
  while (k <= (*UB)) {
    arr[k - 1] = arr[k];
    k = k + 1;
  }
  // 3. Lower UB
  *UB = (*UB) - 1;
  return 0;
};
int insertAtIndex(int arr[], int* UB, int index, int element, const int $LB,
                  const int $MAX) {
  if ((*UB) == $MAX) return 1;                   // Overflow check
  if ((index < $LB) || (index > $MAX)) return 2;  // Index out of bounds.
  // Insert logic.
  // 1. Shift every element till the index forward by one
  // place to create space
  int k = *UB;
  while (k > index) {
    arr[k] = arr[k - 1];
    k = k - 1;
  }
  // 2. Assign element to the now free index.
  arr[index] = element;
  // 3. Raise upper bound
  *UB = (*UB) + 1;

  return 0;
}
// A simple stack
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

/**
 * @brief a simple queue
 * */

//   The queue starts off empty.
Queue::Queue(int size = 5) {
  QUEUE_SIZE = size;
  elements = new int[QUEUE_SIZE];
  front = end = -1;
}

Queue::~Queue() { delete[] elements; }

// We need to be able to add things to the queue
int Queue::enqueue(int element) {
  // Overflow check
  if (isFull()) return 1;
  //   The first thing will make the front=end=0, as the init of the queue
  if (isEmpty()) {
    front = 0;
  }
  //   Other things will stretch out the end of the queue as they are appended.
  end += 1;
  elements[end] = element;
  return 0;
}
// We need to be able to remove things from the queue.
int Queue::dequeue() {
  // Underflow check
  if (isEmpty()) {
    // replace with err enum for testing.
    throw std::logic_error("Underflow in dequeuing queue");
  }
  //   Front goes off, and the next is in front;
  int dequeued = elements[front];
  elements[front] = 0;
  front += 1;
  // When the last person leaves, reset the queue.
  if (front == end) front = end = -1;
  return dequeued;
}

// Convenience methods
//   isFull
bool Queue::isFull() { return (end == (QUEUE_SIZE - 1)); }
//   isEmpty
bool Queue::isEmpty() { return (front == -1 && end == -1); }
//   display
void Queue::display() {
  if (isEmpty()) {
    std::cout << "[| |]";
    return;
  }
  for (int i = front; i <= end; i++) {
    if (i == front) std::cout << "[| <- ";
    std::cout << "[" << elements[i] << "] <- ";
    if (i == end) std::cout << "|]";
  }

  std::cout << "\n";
}
//   count
int Queue::count() {
  if (isEmpty()) return 0;
  return end - front + 1;
}

}  // namespace my_utils
