//! @file Example 5 check if a number is a positive integer
//! (include 0)(alternate impl)
#include <iostream>
using namespace std;

/** @brief  Alternate impl to is_non_negative using else if.
 * Sideeffect: prints you entered 0
 * */
bool is_non_negative_else_if_impl(int number);
int main() {
  int number;
  cout << "Enter a number ";
  cin >> number;

  bool isPositive = is_non_negative_else_if_impl(number);
  if (isPositive) {
    cout << "You entered a Positive integer ";
    return 0;
  }
  // Generally even if it's invalid input
  cout << "Not a positive integer " << endl;
  return 0;
}

bool is_non_negative_else_if_impl(int number) {
  if (number > 0) {
    return true;
  } else if (number == 0) {
    cout << "You entered zero" << endl;
    return true;
  } else
    return false;
};