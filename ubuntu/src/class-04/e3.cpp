//! @file Example 3 create a calculator using switch case for + , - , * , /

#include <iostream>
using namespace std;

int main() {
  int num1, num2, answer;
  char op;
  // Take op
  cout << "Enter the operation:";
  cin >> op;
  //   Check
  if (op != '+' && op != '-' && op != '*' && op != '/') {
    cout << "Invalid operation";
    return -1;
  }
  // Take score
  cout << "Enter first number: ";
  cin >> num1;
  cout << "Enter second number: ";
  cin >> num2;
  switch (op) {
    case '+':
      answer = num1 + num2;
      break;
      break;
    case '-':
      answer = num1 - num2;
      break;
    case '*':
      answer = num1 * num2;
      break;
    case '/':
      answer = num1 / num2;
      break;
    default:
      break;
  }

  cout << "Solution= " << answer << endl;
  return 0;
}