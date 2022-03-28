#include <iostream>
using namespace std;

int main() {
  size_t numbers[2][3];
  cout << "Enter 6 numbers: " << endl;
  for (size_t row = 0; row < 2; row += 1) {
    for (size_t column = 0; column < 3; column++) {
      cin >> numbers[row][column];
    }
  }

  for (size_t row = 0; row < 2; row += 1) {
    for (size_t column = 0; column < 3; column++) {
      cout << "numbers[" << row << "][" << column << "]; "
           << numbers[row][column] << endl;
    }
  }

  return 0;
}
