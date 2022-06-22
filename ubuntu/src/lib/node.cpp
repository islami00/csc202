#include <iostream>

#include "node.h"

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