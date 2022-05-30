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
  // bool wrapper over findIndex
  bool contains(int data);
};
/*convienience*/
SinglyLinkedList::SinglyLinkedList() {
  this->head = nullptr;
  this->tail = nullptr;
}
SinglyLinkedList::~SinglyLinkedList() {
  Node* head = this->head;
  while (head != nullptr) {
    Node* nextNode = head->getNext();
    delete head;
    head = nextNode;
  }
}
void SinglyLinkedList::insert(int data, int index) {
  Node* newNode = new Node(data);
  if (index < 0 || index > size()) {
    cout << "Invalid index" << endl;
    return;
  }
  if (index == 0) {
    newNode->setNext(head);
    head = newNode;
    if (isEmpty()) {
      tail = head;
    }
  } else if (index == size()) {
    if (size() == 1) {
      head->setNext(newNode);
      tail = newNode;
    }
    // index will be more than one, and size will also be more than one.
    tail->setNext(newNode);
    tail = newNode;
  } else {
    // Index >= 1, and index!=size. and size!=1. so index is in [1, size-1]
    Node* temp = head;
    for (int i = 1; i < index; i++) {  // Stop before the index
      if (temp != nullptr) {
        temp = temp->getNext();
      }
    }
    if (temp != nullptr) {
      newNode->setNext(temp->getNext());
      temp->setNext(newNode);
    }
  }
};

void SinglyLinkedList::deleteAtIndex(int index) {
  if (isEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  Node* temp = head;
  if (index == 0) {
    head = temp->getNext();
    delete (temp); /*free*/
    return;
  };
  // Traverse to the node one place before
  for (int i = 0; temp != nullptr && i < index; i++) temp = temp->getNext();
  // Deal with null temp, or next not being a node.
  if (temp == nullptr || temp->getNext() == nullptr) return;
  // here ->  where we want to delete  ->  the node after
  Node* next = temp->getNext()->getNext();
  delete (temp->getNext());
  temp->setNext(next);
};

void SinglyLinkedList::display() {
  std::cout << std::endl;
  // Underflow
  if (isEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  // If only one node
  if (this->size() == 1) {
    std::cout << "Head: ";
    this->head->display();
    std::cout << std::endl;
    return;
  }
  // Traverse list and print all
  Node* ptr = this->head;
  while (ptr != nullptr) {
    if (ptr == this->head) {
      std::cout << "Head: ";
    }
    if (ptr == this->tail) {
      std::cout << " Tail: ";
    }
    ptr->display();
    if (ptr != this->tail) {
      std::cout << "<->";
    }
    std::cout << std::endl;
    ptr = ptr->getNext();
  }
};

int SinglyLinkedList::size() {
  Node* temp = head;
  int i = 0;
  while (temp != nullptr) {
    i++;
    temp = temp->getNext();
  };
  return i;
};

bool SinglyLinkedList::isEmpty() {
  if (head == nullptr) return true;
  return false;
}

Node* SinglyLinkedList::find(int index) {
  if (index < 0 || index > size()) {
    std::cout << "Invalid index" << std::endl;
    return nullptr;
  }
  Node* temp = head;
  Node* found = nullptr;
  for (int i = 0; i <= index && temp != nullptr; i++) {
    if (i == index) {
      found = temp;
    }
    temp = temp->getNext();
  }
  return found;
}
int SinglyLinkedList::findIndex(int data) {
  Node* temp = head;
  int found = -1;
  for (int i = 0; i < size() && temp != nullptr; i++) {
    if (temp->getData() == data) {
      found = i;
    }
    temp = temp->getNext();
  }
  return found;
}

bool SinglyLinkedList::contains(int data) { return findIndex(data) != -1; }
Node* SinglyLinkedList::getHead() { return this->head; }
Node* SinglyLinkedList::getTail() { return tail; }

/** Circular linked list */
class CircularLinkedList : public SinglyLinkedList {
 public:
  /**CORE METHODS*/
  /**
   * Initialise the private variables, Head, tail Head = null, tail = null */
  CircularLinkedList();
  /** Destroy the linked list (follow the next nodes from head till you reach
   * tail, deleting as you go) */
  ~CircularLinkedList();
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
  // bool wrapper over findIndex
  bool contains(int data);
};

/** Doubly linked list */
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
  else if (index == size) {
    if (isEmpty()) {
      this->head->setNext(newNode);
      this->tail = this->head;
      return;
    }
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
    std::cout << "List is empty" << std::endl;
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
    if (current == this->head) {
      std::cout << "Head: ";
    }
    if (current == this->tail) {
      std::cout << " Tail: ";
    }
    current->display();
    if (current != this->tail) {
      std::cout << "<->";
    }
    std::cout << std::endl;
    current = current->getNext();
  }
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
void singlyLinkedListInnerMenu();
void circularLinkedListInnerMenu();
void doublyLinkedListInnerMenu();
// Outer menu --fayyad
void outerMenu();
// Main
#include <assert.h>
int DoublyLinkedListTests();
int main() {
  DoublyLinkedListTests();
  return 0;
}
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
  // assert_insert at tail
  dll->insert(14, 7);
  Node* tail = dll->getTail();
  int tailData = tail->getData();
  assert(tailData == 14);
  dll->display();
  return 0;
}

void singlyLinkedListInnerMenu() {
  int val = 0;
  while (val != 7) {
    cout << "Choose an option" << std::endl
         << "Press 1 for Insert" << std::endl
         << "Press 2 for Delete" << std::endl
         << "Press 3 for Display" << std::endl
         << "Press 4 for Size" << std::endl
         << "Press 5 for find" << std::endl
         << "Press 6 for findindex" << std::endl;
    std::cin >> val;
    // Create the list
    SinglyLinkedList* list = new SinglyLinkedList();
    switch (val) {
      case 1: {
        int data, index;
        Node* head = list->getHead();
        Node** headref = &head;
        cout << "Enter data" << std::endl;
        std::cin >> data;

        cout << "Enter index" << std::endl;
        std::cin >> index;

        list->insert(data, index);
        list->display();
        break;
      }
      case 2: {
        int index;
        cout << "Enter index" << std::endl;
        std::cin >> index;

        list->deleteAtIndex(index);
        list->display();
        break;
      }
      case 3:
        list->display();
        break;

      case 4:
        cout << "Size is " << list->size() << std::endl;
        break;
      case 5: {
        int index;
        cout << "Enter index to find" << std::endl;
        std::cin >> index;
        Node* found = list->find(index);
        if (found != nullptr) {
          cout << "Found " << std::endl;
          found->display();
        } else {
          cout << "Not found" << std::endl;
        }
        break;
      }
      case 6: {
        int data;
        cout << "Enter data to find" << std::endl;
        std::cin >> data;
        int index = list->findIndex(data);
        if (index != -1) {
          cout << "Found at index " << index << std::endl;
        } else {
          cout << "Not found" << std::endl;
        }
        break;
      }
    }
  }
};
void circularLinkedListInnerMenu() {
  /**  int val = 0;
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
      CircularLinkedList* list = new CircularLinkedList();
      switch (val) {
        case 1: {
          int data, index;
          Node* head = list->getHead();
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
    }*/
}
void doublyLinkedListInnerMenu() {
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
    DoublyLinkedList* list = new DoublyLinkedList();
    switch (val) {
      case 1: {
        int data, index;
        DNode* head = list->getHead();
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
        DNode* found = list->find(index);
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
}
void outerMenu() {
  int val = 0;
  while (val != 4) {
    cout << "Choose an option" << endl
         << "Press 1 for singly linked list" << endl
         << "Press 2 for Doubly linked list" << endl
         << "Press 3 for Display" << endl
         << "Press 4 for Exit" << endl;
    cin >> val;
    switch (val) {
      case 1:
        singlyLinkedListInnerMenu();
        break;
      case 2:
        doublyLinkedListInnerMenu();
        break;
      case 3:
        circularLinkedListInnerMenu();
        break;
      case 4:
        break;
    }
  }
}
// Run these to test doubly linked list
