#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
typedef struct Node Node;
// Note: Segmentation fault also occurs when you try to access
// undefined/unallocated areas of mem. E.g creating and object and accessing props before giving value throws undefined err in js. But not here

/**Util for printing node*/
void printNode(Node *nodeRef, char name[40]);

int main() {
  Node *head = (Node *)malloc(sizeof(Node));
  head->data = 1;
  head->next = (Node *)malloc(sizeof(Node));
  char name[40] = "Head";
  printNode(head, name);

  // Each time you traverse, start with a ref to the node then modify that ref.
  // Here, we are filling up the list till "end"
  Node *cursor1 = head->next;
  int end = 6;
  sprintf(name, "Nth");
  for (int i = 2; i <= end; i++) {
    // Fill in data for current node.
    cursor1->data = i;
    // Base case
    if (i == end) {
      cursor1->next = NULL;
      sprintf(name, "Tail");
      printNode(cursor1, name);
      break;
    }
    // Allocate mem for next node,
    cursor1->next = (Node *)malloc(sizeof(Node));
    printNode(cursor1, name);
    // Go forward by one space
    cursor1 = cursor1->next;
  }
  // Finally print.
  printf("\n\tTraversing and printing nodes...\n\n");
  sprintf(name, "Head");
  Node *cursor2 = head;
  for (int j = 0; j < end; j++) {
    if (j != 0) {
      sprintf(name, "Nth");
      if (j == (end - 1))
        sprintf(name, "Tail");
    }
    printNode(cursor2, name);
    cursor2 = cursor2->next;
  }

  return 0;
}

void printNode(Node *nodeRef, char name[40]) {
  printf("%s: %p (%d)-> %p\n", name, nodeRef, nodeRef->data, nodeRef->next);
};