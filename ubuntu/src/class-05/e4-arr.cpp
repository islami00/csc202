#include <iostream>
using namespace std;

int main() {
  size_t numbers[5];
  cout << "Enter 5 numbers: " << endl;
  for (size_t i = 0; i < 5; i += 1) {
    cin >> numbers[i];
  }

  cout << "The numbers are : ";

  for (size_t i = 0; i < 5; i += 1) {
    cout << numbers[i] << " ";
  }
  return 0;
}