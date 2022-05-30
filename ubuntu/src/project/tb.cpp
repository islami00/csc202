#include <iostream>
using namespace std;

class Node
{
private:
 int data;
 Node* next; 
public:
    Node(int data);
    ~Node();
  int getData();

  Node* getNext();

  void setData(int data);

    void setNext(Node* nextNode);
    void display();
};

Node::Node(int data)
{
  this->data = data;
  this->next = nullptr;
}

Node::~Node(){}
int Node::getData() { return this->data; };
Node* Node::getNext() { return this->next; };
void Node::setData(int data) { this->data = data; };
void Node::setNext(Node* nextNode) { this->next = nextNode; };
class SinglyLinkedList{
 private:
  Node* head;
  Node* tail;

 public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  /*node**head is a pointer to an object*/
  void insert(int data, int index);
  void deleteAtIndex(int index);
  void display();
  int size();
  /*convenience*/
  bool isEmpty();
  Node* getHead();
  Node* getTail();
  Node* find(int index);
  int findIndex(int data);
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