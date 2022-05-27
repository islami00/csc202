#include <iostream>
using namespace std;
/** Node:  All class implementations will use this  */
class Node {
 private:
  // Data stored
  int data;
  // A reference to the next node
  Node* next;
  // This won't be used except for doubly linked list.
  Node* prev;

 public:
  //  Creates a node with the specified data
  Node(int data);
  /**
   * Merges prev and next if prev exists, and/or next and prev if next exists,
   * (only in case of doubly linked list), else it's upto the implementer to
   * ensure all memory is accounted for, because it relies on prev which isn't
   * implemented for singular/circular linked lists*/
  ~Node();
  // get data
  int getData();
  // get next
  Node* getNext();
  // get prev
  Node* getPrev();
  // set data
  void setData(int data);
  // Set a reference to the next node
  void setNext(Node* nextNode);
  // Set a reference to the previous node.
  void setPrev(Node* prevNode);
  // Display the data stored in the node
  void display();
};

Node::Node(int data) {
  this->data = data;
  this->next = nullptr;
  this->prev = nullptr;
}

Node::~Node() {
  // This is only valid for doubly linked list. Circular and linear will need to
  // manually manage next refs on delete
  if (this->prev != nullptr) {
    // If something is before us, Fix its next pointer to avoid dangling ref
    Node* nextNode = this->next;
    this->prev->next = nextNode;
  }
  // If something comes after us, Fix its prev pointer
  if (this->next != nullptr) {
    Node* prevNode = this->prev;
    this->next->prev = prevNode;
  }
}
int Node::getData() { return this->data; }
Node* Node::getNext() { return this->next; }
Node* Node::getPrev() { return this->prev; }
void Node::setData(int data) { this->data = data; }
void Node::setNext(Node* nextNode) { this->next = nextNode; }
void Node::setPrev(Node* prevNode) { this->prev = prevNode; }
void Node::display() {
  cout << "[" << this->prev << "|" << this->data << "|" << this->next << "]";
}
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
  /**CORE METHODS*/
  /**
   * Initialise the private variables, Head, tail Head = null, tail = null */
  SinglyLinkedList();
  /** Destroy the linked list (follow the next nodes from head till you reach
   * tail, deleting as you go) */
  ~SinglyLinkedList();
  /** Insert a node with the specified data at an index in the list
   * First node will mutate head, others will mutate tail */
  void insert(int data, int index);
  /** Delete a node at an index in the list, cleaning up the memory */
  void deleteAtIndex(int index);
  /**   Call display on all children, sequentially */
  void display();
  /**   Count the nodes in the list*/
  int size();

  /**CONVENIENCE*/
  /**   Return the head node*/
  Node* getHead();
  /** Return the tail node */
  Node* getTail();
  /**   check if the list is empty*/
  bool isEmpty();
  /**EXTRAS*/
  /**   Find a node at a particular index in the list*/
  Node* find(int index);
  /**   Find the index of a node with a particular piece of data*/
  int findIndex(int data);
};

// Implement each method like this.
// E.g: Constructor
SinglyLinkedList::SinglyLinkedList() {}
// E.g: Destructor
SinglyLinkedList::~SinglyLinkedList() {}
// E.g: Methods
Node* SinglyLinkedList::getHead() { return this->head; }

/*** Doubly linked list */
class DoublyLinkedList {
 private:
  Node* head;
  // Initialised to head
  Node* tail;

 public:
  /**CORE METHODS*/

  DoublyLinkedList();
  // Walk the list from head to tail, deleting each node
  ~DoublyLinkedList();
  /** Insert a node with the specified data at an index in the list
   * First node will mutate head, others will mutate tail */
  void insert(int data, int index);
  /** Delete a node at an index in the list, cleaning up the memory */
  void deleteAtIndex(int index);
  /**   Display all elements in the list, or an equivalent empty
   * representation*/
  void display();
  /**   Count the nodes in the list*/
  int size();

  /**CONVENIENCE*/
  /**   Return the head node*/
  Node* getHead();
  /** Return the tail node */
  Node* getTail();
  /**   check if the list is empty*/
  bool isEmpty();
  /**EXTRAS*/
  /**   Find a node at a particular index in the list, return nullptr if not
   * found*/
  Node* find(int index);
  /**   Find the index of the first node matching a particular piece of data,
   * return -1 if not found*/
  int findIndex(int data);
  // bool wrapper over findIndex
  bool contains(int data);
};

DoublyLinkedList::DoublyLinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
  Node* current = this->head;
  while (current != nullptr) {
    Node* nextNode = current->getNext();
    delete current;
    current = nextNode;
  }
}

void DoublyLinkedList::insert(int data, int index) {
  Node* newNode = new Node(data);
  // Underflow
  if (isEmpty()) {
    // Init: head=tail=newNode
    this->head = newNode;
    this->tail = newNode;
  }
  // Size is definitely >= 1
  // If it's at the head
  else if (index == 0) {
    // Push head down and place newNode at the head
    // new node's prev is null, the default
    newNode->setNext(this->head);
    this->head->setPrev(newNode);
    this->head = newNode;
  }
  // Size is definitely >= 1 and index is definitely >= 1
  // If it's at the tail
  else if (index == this->size() - 1) {
    // Push tail up and place newNode at the tail
    newNode->setPrev(this->tail);
    // new node's Next is null, the default.
    this->tail->setNext(newNode);
    this->tail = newNode;
  }
  // in any other place
  // i.e Index is definitely in range [1, size - 2]
  else {
    // Traverse the list till we get to the node before the insertion point
    Node* current = this->head;
    for (int i = 1; i < index; i++) {
      current = current->getNext();
    }
    // Insert the new node, full process
    Node* nodeAtIndex = current->getNext();
    newNode->setPrev(current);
    newNode->setNext(nodeAtIndex);
    // Fix refs
    nodeAtIndex->setPrev(newNode);
    current->setNext(newNode);
  }
}
void DoublyLinkedList::deleteAtIndex(int index) {
  int size = this->size();
  // Underflow
  if (isEmpty()) {
    // Err out in prod, but print here.
    cout << endl << "Underflow, cannot delete" << endl;
    return;
  } else if (size == 1) {
    // special case, head == tail, hence delete head and reset list to init
    delete this->head;
    this->head = nullptr;
    this->tail = nullptr;
  }
  // Size is definitely > 1 hence, tail must be distinct
  // if it's at the head
  else if (index == 0) {
    // Pop head
    Node* nextNode = this->head->getNext();
    // Ref fixing happens implicitly in destructor, we only have to check
    // tracked refs
    delete this->head;
    this->head = nextNode;

  }
  // if it's at the tail
  else if (index == this->size() - 1) {
    // Pop tail and place it's prev ref as new tail
    Node* prevNode = this->tail->getPrev();
    delete this->tail;
    this->tail = prevNode;
  }
  // In between
  else {
    // Traverse the list till we get to the node before the delete point
    Node* current = this->head;
    for (int i = 1; i < index; i++) {
      current = current->getNext();
    }
    // Delete the node.
    delete current;
  }
};
void DoublyLinkedList::display() {
  // Underflow
  if (isEmpty()) {
    cout << endl << "List is empty" << endl;
    return;
  }
  // If only one node
  if (this->size() == 1) {
    this->head->display();
    cout << endl;
    return;
  }
  // Traverse list and print all
  Node* current = this->head;
  while (current != nullptr) {
    current->display();
    if (current != this->tail) {
      cout << "->";
    }
    current = current->getNext();
  }
  cout << endl;
};
int DoublyLinkedList::size() {
  int size = 0;
  Node* current = this->head;
  while (current != nullptr) {
    size++;
    current = current->getNext();
  }
  return size;
};

Node* DoublyLinkedList::getHead() { return this->head; };
Node* DoublyLinkedList::getTail() { return this->tail; };
bool DoublyLinkedList::isEmpty() { return this->head == nullptr; };
Node* DoublyLinkedList::find(int index) {
  Node* current = this->head;
  for (int i = 0; (i < index) && current != nullptr; i++) {
    current = current->getNext();
  }
  return current;
};
int DoublyLinkedList::findIndex(int data) {
  int index = 0;
  Node* current = this->head;
  while (current != nullptr) {
    if (current->getData() == data) {
      return index;
    }
    current = current->getNext();
    index++;
  }
  return -1;
};

bool DoublyLinkedList::contains(int data) { return findIndex(data) != -1; };

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