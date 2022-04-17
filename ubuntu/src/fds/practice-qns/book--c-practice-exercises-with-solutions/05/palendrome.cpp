#include <string.h>

#include <iostream>
using namespace std;

/**
 * A classic problem, not integers this time. So fast iter.
 * */
bool palendrome(char str[]);
/**
 * Interesting solution, checking array on both ends. I.e i++ and i--. Can also
 * be optimised by stopping at mid and early return
 * */
bool testbook_solution(char *word, int size);
int main() {
  char test[] = "ADA";
  if (palendrome(test)) cout << "It works for " << test << endl;

  char test2[] = "ADAS";
  if (!palendrome(test2))
    cout << "It works (correctly errs) for " << test2 << endl;
  char test3[] = "MADAMIMADAM";
  if (palendrome(test3)) cout << "It works for " << test3 << endl;
  char test4[] = "RACECAR";
  if (palendrome(test4)) cout << "It works for " << test4 << endl;
  return 0;
}

bool palendrome(char str[]) {
  int len = strlen(str);
  int lastIndex = len - 1;
  int middle = len / 2;
  bool is_palendrome = true;
  // Checking against all corresponding positions till middle suffices.
  // is_palendrome condition for quick exit
  for (int i = 0; ((i < middle) && is_palendrome); i++) {
    int complementIndex = lastIndex - i;
    is_palendrome = is_palendrome && (str[i] == str[complementIndex]);
  }
  return is_palendrome;
};
bool testbook_solution(char *word, int size) {
  int i, j;
  for (i = 0, j = size - 1; i < j; i++, j--) {
    if (word[i] != word[j]) return false;
  }
  return true;
}