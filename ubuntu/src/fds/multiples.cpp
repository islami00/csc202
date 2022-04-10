#include <stdio.h>
#include <string.h>
int main() {
  char wordGiven[] = "Mississippi";
  int i = 0;
  char searchLetter = wordGiven[i];  // Avoid null init
  int UB = 0, MAX = strlen(wordGiven);
  char results[MAX];  // Avoid double prints

  // 1. Take every letter in the string
  while (searchLetter != '\0') {
    // Optimisation: Avoid printing the same letter twice
    int hasBeenChecked = 0;
    for (int n = 0; n < UB; n++) {
      if (searchLetter == results[n]) {
        hasBeenChecked = 1;
        break;
      }
    }
    if (hasBeenChecked) {
      // Go to next
      i = i + 1;
      searchLetter = wordGiven[i];
      continue;
    } else {
      // Memoise.
      results[UB] = searchLetter;
      UB = UB + 1;
    }
    // Solution continued...
    int indexStore[MAX];
    int indices = 0, j = 0;
    char currentLetter = wordGiven[j];  // Avoid null init
    // 2. Look through the string and store each index the letter is found in.
    while (currentLetter != '\0') {
      if (currentLetter == searchLetter) {
        indexStore[indices] = j;
        indices += 1;
      }
      j = j + 1;
      currentLetter = wordGiven[j];
    }
    // 3. If searchLetter is found more than once, print the indices.
    if (indices > 1) {
      printf("\n%c occurs more than once, and is found at:\n", searchLetter);
      for (int k = 0; k < indices; k++) {
        printf("%d ", indexStore[k]);
      }
    }
    i = i + 1;
    searchLetter = wordGiven[i];
  }

  return 0;
}