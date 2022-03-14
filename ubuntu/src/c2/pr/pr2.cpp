#include <iostream>
using namespace std;

void odd(int);
void even(int);

int main() {
  int i;
  do {
    cout << "Please enter a number, (0 to exit) ";
    cin >> i;
    odd(i);
  } while (i != 0);
  return 0;
}
// No invariant for x not int;

void odd(int x) {
  if ((x % 2) != 0)
    cout << "It is odd.\n";
  else
    even(x);
}
void even(int x) {
  if ((x % 2) == 0)
    cout << "It is even.\n";
  else
    odd(x);
}
