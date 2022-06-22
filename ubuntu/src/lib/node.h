#if !defined(NODE_H)
#define NODE_H

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

#endif  // NODE_H
