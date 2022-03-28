#include <iostream>

using namespace std;
size_t factorial(size_t);
int main() {
  size_t n, result;
  cout << "Enter a non-negative number: ";
  cin >> n;

  result = factorial(n);
  cout << "Factorial of  " << n << " = " << result;
  return 0;

  return 0;
}
size_t memo[500];
size_t factorial(size_t num) {
  // useMemo
  if (memo[num] != 0) {
    return memo[num];
  }

  if (num > 1) {
    size_t nthFac = num * factorial(num - 1);
    // Memoise
    memo[num] = nthFac;
    return nthFac;
  } else
    return 1;
};
