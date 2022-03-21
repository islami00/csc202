#include <iostream>

using namespace std;

int main() {
  int i = 1;
  int sum = 0;
  while (i <= 10) sum += i++;  // cheeky one-liner
  cout << sum;
  return 0;
}