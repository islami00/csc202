#ifndef LIB_H
#define LIB_H

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

#define MAX_STACK_SIZE 4
/**
 * Example stack impl in cpp
 * */
class Stack {
  /* data */
  int length;

 public:
  unsigned int st[MAX_STACK_SIZE];  // Stack of 4. Value limited to unsigned for
                                    // pop method.
  Stack();
  ~Stack();
  int push(int item);
  int pop();
};
}  // namespace my_utils

#endif  // !