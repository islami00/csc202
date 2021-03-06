#include <lib.h>

using namespace std;

/**
 * Simple solution: Copy to new arr after applying the mapping.
 * ShiftRightMapping := i -> (i + n) % size for all  i in validIndexSet
 * Mutates input array.
 * */
void shiftRight(int arr[], int size, int n);
void initTest(int arr[]);
void tests(char testStr[20]);
int modulo(int num, int base);
int main() {
  char input[20];
  int success = 0, failures = 0, n = 0;
  tests(input);
  sscanf(input, "%d %d %d", &success, &failures, &n);
  cout << "Ran " << n << " Tests\n";
  cout << "Tests Passed: " << success << "\n";
  cout << "Tests failed: " << failures << "\n";
  return 0;
}
int modulo(int num, int base) {
  int baseMod = num % base;
  int modulo = baseMod;
  if (modulo < 0) modulo = modulo + base;
  return modulo;
};

void shiftRight(int arr[], int size, int n) {
  // Shift n times has same effect as shift n % size times;
  int cleanN = modulo(n, size);
  int resArr[size];
  for (size_t i = 0; i < size; i++) {
    //   Apply mapping. Modulo size to ensure we don't overflow bounds.
    int map = (i + cleanN) % size;
    resArr[map] = arr[i];
  }
  //   Copy into original arr
  for (size_t i = 0; i < size; i++) {
    arr[i] = resArr[i];
  }
};

void initTest(int arr[5]) {
  for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
  }
};
void tests(char testStr[20]) {
  int success = 0;
  int failed = 0;
  int size = 5;
  int test[size] = {1, 2, 3, 4, 5};
  //   Support for negative
  shiftRight(test, size, -1);
  int expected[size] = {2, 3, 4, 5, 1};
  bool is_eq = my_utils::arr_eq(test, expected, size, size);
  success += 1;
  if (!is_eq) {
    failed += 1;
    success -= 1;
    cout << "Reverse shift for negative numbers doesn't work!\n";
  }
  //   Modulo identity of negative shifts
  initTest(test);
  shiftRight(test, size, -1 + size);
  is_eq = my_utils::arr_eq(test, expected, size, size);
  success += 1;
  if (!is_eq) {
    failed += 1;
    success -= 1;
    cout << "Modulo identity for negative shifts doesn't hold\n";
  }
  // Support for positive
  initTest(test);
  shiftRight(test, size, 2);
  int expected2[size] = {4, 5, 1, 2, 3};
  is_eq = my_utils::arr_eq(test, expected2, size, size);
  success += 1;
  if (!is_eq) {
    failed += 1;
    success -= 1;
    cout << "Doesn't support shifts forward by positive number of places\n";
  }
  //   Modulo identity. 2+size. 2 from prev.
  initTest(test);
  shiftRight(test, size, 2 + size);
  is_eq = my_utils::arr_eq(test, expected2, size, size);
  success += 1;
  if (!is_eq) {
    failed += 1;
    success -= 1;
    cout << "Modulo identity for positive shifts doesn't hold\n";
  }
  sprintf(testStr, "%d %d %d", success, failed, success + failed);
}