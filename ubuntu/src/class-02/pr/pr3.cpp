
#include <iostream>
using namespace std;

int max(int, int);

int main() {
  // Local vars
  int a = 100, b = 200;
  int ret;

  ret = max(a, b);
  cout << "Max value is: " << ret << "\n";
  return 0;
}

int max(int x, int y) {
  if (x > y) return x;
  if (y > x) return y;
}
