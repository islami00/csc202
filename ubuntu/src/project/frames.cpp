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
   * Merges prev and next if prev exists (only in case of doubly linked list),
   * else it's upto the implementer to ensure all memory is accounted for,
   * because Deleting prev and next would be destructive given we're
   * implementing a list, we want to pick this node out and delete it.*/
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
};

Node::Node(int data) {
  this->data = data;
  this->next = nullptr;
  this->prev = nullptr;
}

Node::~Node() {
  if (this->prev != nullptr) {
    Node* nextNode = this->next;
    this->prev->next = nextNode;
  }
}
int Node::getData() { return this->data; }
Node* Node::getNext() { return this->next; }
Node* Node::getPrev() { return this->prev; }
void Node::setData(int data) { this->data = data; }
void Node::setNext(Node* nextNode) { this->next = nextNode; }
void Node::setPrev(Node* prevNode) { this->prev = prevNode; }

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