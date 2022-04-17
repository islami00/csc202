#include <iostream>

using namespace std;
// Recursive harmonics
double harmony(int);
// Iterative harmonics
double harmonyIter(int);

int main() {
  int n = 5;
  cout << "Fifth harmonic is " << harmony(5) << "\n";
  cout << "Assuming it is same for iter\n";
  cout << "Fifth harmonic is " << harmonyIter(5);

  return 0;
}
double harmony(int n) {
  if (n == 1) {
    return 1;
  }
  // recurse
  return 1 / ((double)n) + harmony(n - 1);
}
double harmonyIter(int n) {
  double harmonic = 0;
  for (double i = 1; i <= n; i++) {
    harmonic += 1 / i;
  }
  return harmonic;
}