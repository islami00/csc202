#include <iostream>
using namespace std;

/** Node:  All class implementations will use this  */
class Node {
 private:
  // Data stored
  int data;
  // A reference to the next node
  Node* next;

 public:
  //  Creates a node with the specified data
  Node(int data);
  ~Node();
  // get data
  int getData();
  // get next
  Node* getNext();
  // set data
  void setData(int data);
  // Set a reference to the next node
  void setNext(Node* nextNode);
  // Display the data stored in the node
  void display();
};

Node::Node(int data) {
  this->data = data;
  this->next = nullptr;
}
Node::~Node() {}
int Node::getData() { return this->data; }
Node* Node::getNext() { return this->next; }
void Node::setData(int data) { this->data = data; }
void Node::setNext(Node* nextNode) { this->next = nextNode; }
void Node::display() {
  std::cout << "[" << this->data << "|" << this->next << "]";
}

/**DNode specialisation for doubly linked list*/
class DNode : public Node {
 private:
  // A reference to the previous node
  DNode* prev;

 public:
  //  Creates a node with the specified data
  DNode(int data);
  /**
   * Merges prev and next if prev exists, and/or next and prev if next exists,
   * (only in case of doubly linked list), else it's upto the implementer to
   * ensure all memory is accounted for, because it relies on prev which isn't
   * implemented for singular/circular linked lists*/
  ~DNode();
  // Override getNext
  DNode* getNext();

  // get prev
  DNode* getPrev();
  // set prev
  void setPrev(DNode* prevNode);
  // Display the data stored in the node
  void display();
};
DNode::DNode(int data) : Node(data) { this->prev = nullptr; }
DNode::~DNode() {
  if (this->prev != nullptr) {
    // If something is before us, Fix its next pointer to avoid dangling ref
    DNode* nextNode = this->getNext();
    this->prev->setNext(nextNode);
  }
  // If something comes after us, Fix its prev pointer
  if (this->getNext() != nullptr) {
    DNode* prevNode = this->prev;
    DNode* nextNode = this->getNext();
    nextNode->setPrev(prevNode);
  }
}
DNode* DNode::getNext() { return (DNode*)Node::getNext(); }
DNode* DNode::getPrev() { return this->prev; }
void DNode::setPrev(DNode* prevNode) { this->prev = prevNode; }
void DNode::display() {
  std::cout << "[" << this->prev << "|" << this->getData() << "|"
            << this->getNext() << "]";
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
  DNode* head;
  // Initialised to head
  DNode* tail;

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
  DNode* getHead();
  /** Return the tail node */
  DNode* getTail();
  /**   check if the list is empty*/
  bool isEmpty();
  /**EXTRAS*/
  /**   Find a node at a particular index in the list, return nullptr if not
   * found*/
  DNode* find(int index);
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
  DNode* current = this->head;
  while (current != nullptr) {
    DNode* nextNode = current->getNext();
    delete current;
    current = nextNode;
  }
}

void DoublyLinkedList::insert(int data, int index) {
  int size = this->size();
  // Overflow, underflow
  if (index < 0) {
    std::cout << "Underflow, Index out of range, cannot insert" << std::endl;
    return;
  }
  if (index > size) {
    std::cout << "Overflow, Index out of range, cannot insert" << std::endl;
    return;
  }
  DNode* newNode = new DNode(data);
  // Size is definitely >= 1
  // If it's at the head
  if (index == 0) {
    // Empty case
    if (isEmpty()) {
      this->head = newNode;
      this->tail = this->head;
      return;
    }
    // Push head down and place newNode at the head
    // new node's prev is null, the default
    newNode->setNext(this->head);
    this->head->setPrev(newNode);
    this->head = newNode;
  }
  // If it's at the tail
  // Size is definitely >= 1 and index is definitely >= 1
  else if (index == (size - 1)) {
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
    DNode* current = this->head;
    for (int i = 1; i < index; i++) {
      current = current->getNext();
    }
    // Insert the new node, full process
    DNode* nodeAtIndex = current->getNext();
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
    std::cout << std::endl << "Underflow, cannot delete" << std::endl;
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
    DNode* nextNode = this->head->getNext();
    // Ref fixing happens implicitly in destructor, we only have to check
    // tracked refs
    delete this->head;
    this->head = nextNode;

  }
  // if it's at the tail
  else if (index == this->size() - 1) {
    // Pop tail and place it's prev ref as new tail
    DNode* prevNode = this->tail->getPrev();
    delete this->tail;
    this->tail = prevNode;
  }
  // In between
  else {
    // Traverse the list till we get to the node before the delete point
    DNode* current = this->head;
    for (int i = 1; i < index; i++) {
      current = current->getNext();
    }
    // Delete the node.
    delete current;
  }
};
void DoublyLinkedList::display() {
  std::cout << std::endl;
  // Underflow
  if (isEmpty()) {
    std::cout << std::endl << "List is empty" << std::endl;
    return;
  }
  // If only one node
  if (this->size() == 1) {
    this->head->display();
    std::cout << std::endl;
    return;
  }
  // Traverse list and print all
  DNode* current = this->head;
  while (current != nullptr) {
    current->display();
    if (current != this->tail) {
      std::cout << "<->";
    }
    current = current->getNext();
  }
  std::cout << std::endl;
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

DNode* DoublyLinkedList::getHead() { return this->head; };
DNode* DoublyLinkedList::getTail() { return this->tail; };
bool DoublyLinkedList::isEmpty() { return this->head == nullptr; };
DNode* DoublyLinkedList::find(int index) {
  if (index < 0 || index >= this->size()) {
    // Err out
    std::cout << "Overflow/Underflow in find at DoublyLinkedList, index out of "
                 "bounds";
    return nullptr;  // nf
  }
  DNode* found = nullptr;
  DNode* current = this->head;
  for (int i = 0; (i < index) && current != nullptr; i++) {
    current = current->getNext();
    if (i == index - 1) {
      found = current;
      break;
    }
  }
  return found;
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
void singlyLinkedListInnerMenu() {
  int val = 0;
  while (val != 7) {
    cout << "Choose an option" << endl
         << "Press 1 for Insert" << endl
         << "Press 2 for Delete" << endl
         << "Press 3 for Display" << endl
         << "Press 4 for Size" << endl
         << "Press 5 for find" << endl
         << "Press 6 for findindex" << endl;
    cin >> val;
    // Create the list
    SinglyLinkedList* list = new SinglyLinkedList();
    switch (val) {
      case 1: {
        int data, index;
        Node* head = list->getHead();
        Node** headref = &head;
        cout << "Enter data" << endl;
        cin >> data;

        cout << "Enter index" << endl;
        cin >> index;

        list->insert(data, index);
        list->display();
        break;
      }
      case 2: {
        int index;
        cout << "Enter index" << endl;
        cin >> index;

        list->deleteAtIndex(index);
        list->display();
        break;
      }
      case 3:
        list->display();
        break;

      case 4:
        cout << "Size is " << list->size() << endl;
        break;
      case 5: {
        int index;
        cout << "Enter index to find" << endl;
        cin >> index;
        Node* found = list->find(index);
        if (found != nullptr) {
          cout << "Found " << endl;
          found->display();
        } else {
          cout << "Not found" << endl;
        }
        break;
      }
      case 6: {
        int data;
        cout << "Enter data to find" << endl;
        cin >> data;
        int index = list->findIndex(data);
        if (index != -1) {
          cout << "Found at index " << index << endl;
        } else {
          cout << "Not found" << endl;
        }
        break;
      }
    }
  }
};
void doublyLinkedListInnerMenu();
void circularLinkedListInnerMenu(){};
// Outer menu --fayyad
void outerMenu();
// Main
#include <assert.h>
int DoublyLinkedListTests();
int main() {
  DoublyLinkedListTests();
  return 0;
}

// Run these to test doubly linked list
int DoublyLinkedListTests() {
  DoublyLinkedList* dll = new DoublyLinkedList();
  dll->display();
  // Assert_isEmpty!
  bool isEmpty = dll->isEmpty();
  assert(isEmpty == true);
  dll->insert(1, 0);
  dll->display();
  // Assert_isEmpty!
  isEmpty = dll->isEmpty();
  assert(isEmpty == false);
  // Assert_size!
  int size = dll->size();
  assert(size == 1);
  dll->insert(2, 0);
  dll->display();
  // Assert_size!
  size = dll->size();
  assert(size == 2);
  dll->insert(3, 0);
  dll->display();
  dll->insert(4, 0);
  dll->display();
  // Assert_contains and findIndex and find
  bool contains = dll->contains(4);
  assert(contains == true);
  int indexFound = dll->findIndex(4);
  assert(indexFound == 0);
  DNode* nodeAtIndex = dll->find(1);
  int nodeData = nodeAtIndex->getData();
  assert(nodeData == 3);
  // Assert_deleteAtIndex
  dll->deleteAtIndex(0);
  dll->display();
  size = dll->size();
  assert(size == 3);
  indexFound = dll->findIndex(4);
  assert(indexFound == -1);
  contains = dll->contains(4);
  assert(contains == false);
  nodeAtIndex = dll->find(-1);
  assert(nodeAtIndex == nullptr);
  DNode* tailNode = dll->getTail();
  nodeData = tailNode->getData();
  assert(nodeData == 1);
  // inserting at > 0 indices
  dll->insert(10, 1);
  dll->display();
  size = dll->size();
  assert(size == 4);
  indexFound = dll->findIndex(10);
  assert(indexFound == 1);
  dll->insert(11, 1);
  dll->insert(12, 2);
  dll->insert(13, 3);
  size = dll->size();

  assert(size == 7);
  indexFound = dll->findIndex(11);
  assert(indexFound == 1);
  indexFound = dll->findIndex(12);
  assert(indexFound == 2);
  indexFound = dll->findIndex(13);
  assert(indexFound == 3);
  indexFound = dll->findIndex(10);
  assert(indexFound == 4);
  dll->display();
  // Inserting at out of bounds indices is idempotent
  dll->insert(199, 12);
  size = dll->size();
  assert(size == 7);
  return 0;
}