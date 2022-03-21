//! @file EXAMPLE 4 CHECK IF A NUMBER IS A POSITIVE INTEGER (INCLUDE 0)
#include <iostream>
using namespace std;

/** @brief  Alternate impl to is_non_negative using else.*/
bool is_non_negative_else_impl(int number);
int main() {
  int number;
  cout << "Enter a number ";
  cin >> number;

  bool isPositive = is_non_negative_else_impl(number);
  if (isPositive) {
    cout << "Positive integer ";
    return 0;
  }
  // Generally even if it's invalid input
  cout << "Not a positive integer " << endl;
  return 0;
}

bool is_non_negative_else_impl(int number) {
  if (number >= 0) {
    return true;
  } else
    return false;
};