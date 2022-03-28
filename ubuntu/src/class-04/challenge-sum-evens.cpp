#include <iostream>

using namespace std;

int main() {
  int i = 1;
  int sum = 0;
  while (i < 20) {
    if ((i % 2) != 0) {
      i++;
      continue;
    }
    sum += i++;
  }
  cout << sum;
  return 0;
}