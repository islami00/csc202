/** Node:  All class implementations will use this  */
class Node {
 private:
  int data;
  Node* next;
  // This won't be used except for doubly linked list.
  Node* prev;

 public:
  Node(int data);
  ~Node();
  // Set a reference to the next node
  void setNext(Node* nextNode);
  // Set a reference to the previous node.
  void setPrev(Node* prevNode);
};

Node::Node(int data) {}

Node::~Node() {}

/** List classes implemenetations
 * Singly linked list:  Tobechi
 * Circular linked list:  Salim
 * Doubly linked list:  Islam
 *  */
// E.g: 1. Singly linked list
class SinglyLinkedList {
 private:
  Node* head;
  // Initialised to head
  Node* tail;

 public:
  /**Core methods*/
  // Initialise the private variables, Head, tail
  //   Head = null, tail = null
  SinglyLinkedList();
  // Destroy the linked list (follow the next nodes from head till you reach
  // tail, deleting as you go)
  ~SinglyLinkedList();
  // Insert a node with the specified data at an index in the list
  //   First node will mutate head, others will mutate tail
  void insert(int data, int index);
  // Delete a node at an index in the list, cleaning up the memory
  void deleteAtIndex(int index);
  //   Display all elements in the list, or an equivalent empty representation
  void display();
  //   Count the nodes in the list
  int size();

  /**convenience*/
  //   Return the head node
  Node* head();
  // Return the tail node
  Node* tail();
  //   check if the list is empty
  bool isEmpty();
  /**Extrass*/
  //   FInd a node at a particular index in the list
  Node* find(int index);
  //   Find the index of a node with a particular piece of data
  int findIndex(int data);
};

// Implement each method like this.
// E.g: Constructor
SinglyLinkedList::SinglyLinkedList() {}
// E.g: Destructor
SinglyLinkedList::~SinglyLinkedList() {}
// E.g: Methods
Node* SinglyLinkedList::head() {}

/** Inner menus -- zaid */
void singlyLinkedListInnerMenu();
void doublyLinkedListInnerMenu();
void circularLinkedListInnerMenu();
// Outer menu --fayyad
void outerMenu();
// Main
int main() {
  outerMenu();
  return 0;
}