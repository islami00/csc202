#if !defined(D_NODE_H)
#define D_NODE_H

#include "node.h"

/**DNode specialisation for doubly linked list*/
class DNode : public Node {
 private:
  // A reference to the previous node
  DNode* prev;

 public:
  //  Creates a node with the specified data
  DNode(int data);
  /**destructor does nothing for locality of algo ref. */
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

#endif  // D_NODE_H
