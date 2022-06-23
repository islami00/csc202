#include <iostream>

#include "islgr_util.h"
#include "lib.h"
using namespace std;
#define MAX 9
#define LB 0

int main() {
  // UB = len
  int UB = MAX;
  int stock[MAX] = {1, 2, 4, 2, 12, 3, 3, 3, 3};
  int indexCounter = 0;
  // Rewrite the beginning of the array with unique elements.
  for (int i = 0; i < UB; i++) {
    int n = stock[i];
    bool sortedFound = false;
    // find n.
    for (int j = 0; j <= indexCounter; j++) {
      int m = stock[j];
      if (m == n) {
        sortedFound = true;
        break;
      }
    }
    // if it's not found anywhere in sorted arr, add to sorted section
    if (!sortedFound) {
      indexCounter += 1;
      stock[indexCounter] = n;
    }
  }
  // Clear everywhere else from bottom.
  //   using maxIndex because deleteAtIndex was modeled with ub=maxIndex, not
  //   ub=len
  int maxIndex = UB - 1;
  for (int k = maxIndex; k > indexCounter; k--) {
    my_utils::deleteAtIndex(stock, &maxIndex, k, LB, MAX);
  }
  UB = maxIndex + 1;
  my_utils::prettyPrint(stock, UB);
  return 0;
}
