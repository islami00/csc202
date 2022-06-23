#ifndef LIB_H
#define LIB_H

#include <iostream>
namespace my_utils {
/**
 * Add two numbers
 *
 * */
int sum(int a, int b);
// ToDo: Modify this so we can Pass in an array of length n to specify scale.
// I.e {90,80,70,60} (<60 is F, >=90 is A, Fill in the bits) This helps give us
// a more flexible grading system We could also serialise ourselves. Asking for
// a maximum, minimum, and interval,

/**
 * @brief      Calculates the grade on a scale of A,B,C,D,F with A at 90, F < 60
 * and an interval of 10. Serialises for use in switch via integer division
 * hence not suitable for smaller intervals. Cp-ed from class.
 *
 * @param[in]  score  The score
 *
 * @return Returns the grade character or null if score not in range 0-100
 * */
char find_grades(int score);

/**
 * @brief      Check if a number is non-negative.
 *
 * @param[in]  number  The number. Preferrably an integer.
 *
 * @return   success.
 */
bool is_non_negative(int number);
/**
 * @brief Pretty print and array of integers
 * */
void prettyPrint(int arr[], size_t arr_size);
/**
 * @brief Checks if two arrays of the same length are equal. You specify length
 * so you don't mix it up.
 * */
bool arr_eq(int arr1[], int arr2[], int arr1_size, int arr2_size);
#define STACK_SIZE 3
/**
 * Example stack impl in cpp
 * */
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
#define QUEUE_SIZE 3
/**
 * We need a queue
 * */
class Queue {
 private:
  int front;
  int end;
  int elements[QUEUE_SIZE];

 public:
  Queue();
  ~Queue();
  int enqueue(int element);
  int dequeue();
  bool isFull();
  bool isEmpty();
  void display();
  int count();
};
/**
 * Delete at an index in an array
 * Where LB is the last index of the array,e.g (0)
 * And MAX is the maximum Length of the array, e.g (10)
 * And UB is the current Highest index of the array, e.g (5) - This need not be
 * equal to MAX
 */
int deleteAtIndex(int arr[], int* UB, int index, const int LB, const int MAX);

}  // namespace my_utils

#endif  // !