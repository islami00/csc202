#include <iostream>
using namespace std;

bool is_even(int);

int main() {
  int i;
  cout << "Please enter a number ";
  cin >> i;
  bool even = is_even(i);
  if (even)
    cout << i << " Is even" << endl;
  else
    cout << i << " Is odd" << endl;
  return 0;
}
// Nice util. Move.
bool is_even(int x) {
  if ((x % 2) == 0)
    return true;
  else
    return false;
}
