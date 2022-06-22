#include "dnode.h"

#include <iostream>
DNode::DNode(int data) : Node(data) { this->prev = nullptr; }
DNode::~DNode() {}
DNode* DNode::getNext() { return (DNode*)Node::getNext(); }
DNode* DNode::getPrev() { return this->prev; }
void DNode::setPrev(DNode* prevNode) { this->prev = prevNode; }
void DNode::display() {
  std::cout << "[" << this->prev << "|" << this->getData() << "|"
            << this->getNext() << "]";
}