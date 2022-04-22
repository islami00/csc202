#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
typedef struct Node Node;
// Segmentation fault also occurs when you try to access undefined/unallocated
// areas of mem

/**Util for printing node*/
void printNode(Node *nodeRef, char name[40]);

int main() {
  Node *head = (Node *)malloc(sizeof(Node));
  Node *second = (Node *)malloc(sizeof(Node));
  head->data = 1;
  head->next = second;
  char name[40] = "head";
  printNode(head, name);

  second->data = 2;
  second->next = (Node *)malloc(sizeof(Node));
  sprintf(name, "second");
  printNode(second, name);
  sprintf(name, "Nth");

  // Each time you traverse, start with a ref to the node then modify that ref.
  Node *nth = second->next;
  for (int i = 3; i <= 4; i++) {
    // Fill in data for current node.
    nth->data = i;
    if (i == 4) {
      // Base case
      nth->next = NULL;
      printNode(nth, name);
      break;
    }
    // Allocate mem for next node,
    nth->next = (Node *)malloc(sizeof(Node));
    printNode(nth, name);
    // Go forward by one space
    nth = nth->next;
  }
  // Finally print.
  printf("Traversing and printing nodes...\n");
  sprintf(name, "head");
  Node *cursor = head;
  for (int j = 0; j < 4; j++) {
    printNode(cursor, name);
    if (j == 1)
      sprintf(name, "second");
    else
      sprintf(name, "nth");
    cursor = cursor->next;
  }

  return 0;
}

void printNode(Node *nodeRef, char name[40]) {
  printf("%s: %p (%d)-> %p\n", name, nodeRef, nodeRef->data, nodeRef->next);
};