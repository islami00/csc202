//! @file Example 1. Switch case demo

#include <iostream>
using namespace std;
int main() {
  int number;
  cout << "To check grade enter a number:";
  cin >> number;
  switch (number) {
    case 2:
      cout << "It is 2";
      break;
    case 3:
      cout << "It is 3";
      break;
    case 4:
      cout << "It is 4";
      break;
    default:
      cout << "Not 2,3,4";
      break;
  }
}