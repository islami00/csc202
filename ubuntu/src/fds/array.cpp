#include <stdio.h>
#define MAX 10
#define LB 0
// Here, we take the upper bound as the current length of the array, Not the
// last index. We also take max as the max size of the array, not the last
// index. LB is both the least size and start index of the array.

//
/**
 * Insert at a specific index.
 * UB is passed as a pointer because it is changed while inserting.
 */
int insertAtIndex(int arr[], int* UB, int index, int element);
/** Wrapper for insertAt zero */
int insertAtBeginning(int arr[], int* UB, int element);
/** Wrapper for insertAt UB /  2. */
int insertAtMiddle(int arr[], int* UB, int element);
/** Wrapper for insertAt UB */
int insertAtEnd(int arr[], int* UB, int element);
/**
 * Delete an element at a specific index.
 * */
int deleteAtIndex(int arr[], int* UB, int index);
/** Wrapper for deleteAt zero */
int deleteAtBeginning(int arr[], int* UB);
/** Wrapper for deleteAt UB / 2 */
int deleteAtMiddle(int arr[], int* UB);
/** Wrapper for deleteAt UB */
int deleteAtEnd(int arr[], int* UB);

int main() {
  for (size_t i = 1; i <= 6; i++) {
    int test[MAX] = {7, 5, 20, 23};
    int _UB = 4;
    int res;
    // 1. Insert at beginning
    if (i == 1) {
      printf("Inserting at beginning\n");
      res = insertAtBeginning(test, &_UB, 22);
    }
    // 2. Insert at middle
    if (i == 2) {
      printf("Inserting at middle\n");
      res = insertAtMiddle(test, &_UB, 22);
    }
    // 3. Insert at end
    if (i == 3) {
      printf("Inserting at end\n");
      res = insertAtEnd(test, &_UB, 22);
    }
    // 4. Delete at beginning
    if (i == 4) {
      printf("Deleting at beginning\n");
      res = deleteAtBeginning(test, &_UB);
    }
    // 5. Delete at middle
    if (i == 5) {
      printf("Deleting at middle\n");
      res = deleteAtMiddle(test, &_UB);
    }
    // 6. Delete at end
    if (i == 6) {
      printf("Deleting at end\n");
      res = deleteAtEnd(test, &_UB);
    }
    // Output.
    if (res == 1)
      printf("Overflow\n");
    else if (res == 2)
      printf("Index out of bounds\n");
    else {
      for (int n = 0; n < _UB; n++) {
        printf("arr[%d] = %d\n", n, test[n]);
      }
    }
  }

  return 0;
}

int insertAtIndex(int arr[], int* UB, int index, int element) {
  if ((*UB) == MAX) return 1;                   // Overflow check
  if ((index < LB) || (index > MAX)) return 2;  // Index out of bounds.
  // Insert logic.
  // 1. Shift every element till the index forward by one
  // place to create space
  int k = *UB;
  while (k > index) {
    arr[k] = arr[k - 1];
    k = k - 1;
  }
  // 2. Assign element to the now free index.
  arr[index] = element;
  // 3. Raise upper bound
  *UB = (*UB) + 1;

  return 0;
};
int insertAtBeginning(int arr[], int* UB, int element) {
  return insertAtIndex(arr, UB, 0, element);
};
int insertAtMiddle(int arr[], int* UB, int element) {
  return insertAtIndex(arr, UB, (*UB) / 2, element);
};
int insertAtEnd(int arr[], int* UB, int element) {
  return insertAtIndex(arr, UB, *UB, element);
};

int deleteAtIndex(int arr[], int* UB, int index) {
  if ((*UB) == LB) return 1;                    // Underflow
  if ((index < LB) || (index > MAX)) return 2;  // Out of bounds

  // Delete logic
  // 1. Clear position
  arr[index] = NULL;
  // 2. Move every element backwards by one place to fill space
  int k = index + 1;
  while (k <= (*UB)) {
    arr[k - 1] = arr[k];
    k = k + 1;
  }
  // 3. Lower UB
  *UB = (*UB) - 1;
  return 0;
};
int deleteAtBeginning(int arr[], int* UB) { return deleteAtIndex(arr, UB, 0); };
int deleteAtMiddle(int arr[], int* UB) {
  return deleteAtIndex(arr, UB, (*UB) / 2);
};
int deleteAtEnd(int arr[], int* UB) { return deleteAtIndex(arr, UB, *UB); };