#include <iostream>
#define QUEUE_SIZE 3
// We need a queue
class Queue {
 private:
  int front;
  int end;
  int elements[QUEUE_SIZE];

 public:
  Queue();
  ~Queue();
  int enqueue(int element);
  int dequeue();
  bool isFull();
  bool isEmpty();
  void display();
};

//   The queue starts off empty.
Queue::Queue() {
  //   The front=end which is right before the queue (-1).
  front = end = -1;
}

Queue::~Queue() {}

// We need to be able to add things to the queue
int Queue::enqueue(int element) {
  // Overflow check
  if (isFull()) return 1;
  //   The first thing will make the front=end=0, as the init of the queue
  if (front = -1) {
    front = 0;
  }
  //   Other things will stretch out the end of the queue as they are appended.
  end += 1;
  elements[end] = element;
  return 0;
}
// We need to be able to remove things from the queue.
int Queue::dequeue() {
  // Underflow check
  if (isEmpty()) {
    throw std::logic_error("Underflow in dequeuing queue");
  }
  //   Removing something will make every other thing shift forward and shrink
  //   our end
  int dequeued = elements[front];
  for (int i = front; i < end; i++) {
    elements[i] = elements[i + 1];
  }
  end -= 1;
  //   Removing the last thing will cover up our queue and make
  //   front=end=-1
  if (end == -1) front = -1;
  return dequeued;
}

// Convenience methods
//   isFull
bool Queue::isFull() { return (end + 1) == QUEUE_SIZE; }
//   isEmpty
bool Queue::isEmpty() { return front == -1; }
//   display
void Queue::display() {
  if (isEmpty()) {
    std::cout << "[| |]";
    return;
  }
  // Doesn't handle case where i = front=end =-1;
  for (int i = front; i <= end; i++) {
    if (i == front) std::cout << "[| <- ";
    std::cout << "[" << elements[i] << "] <- ";
    if (i == end) std::cout << "|]";
  }

  std::cout << "\n";
}
int test();
int main() { return test(); }
int test() {
  // We should be able to start an empty queue.
  Queue q;
  if (!q.isEmpty()) {
    throw std::logic_error("Is empty failed on an empty queue");
  }
  // Enqueue a few items
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  int enqueueRetCode = q.enqueue(4);
  bool enqueueOverflowGuardWorks = enqueueRetCode == 1;
  if (!q.isFull()) {
    throw std::logic_error("Is full failed on a full queue");
  }
  if (!enqueueOverflowGuardWorks) {
    throw std::logic_error("Enqueue does not handle overflow");
  }
  //   Should see a pretty full queue on screen
  q.display();
  //   Dequeue to empty
  int one = q.dequeue();
  int two = q.dequeue();
  int three = q.dequeue();
  bool dequeueUnderflowGuardWorks = false;
  try {
    // This last one should fail
    q.dequeue();
  } catch (const std::exception& e) {
    dequeueUnderflowGuardWorks = true;
  }
  if (!q.isEmpty()) {
    // dequeing failed
    throw std::logic_error("Dequeing failed!");
  }
  if (!dequeueUnderflowGuardWorks) {
    throw std::logic_error("Dequeue does not handle underflow");
  }
  // Should show us a properly empty queue
  q.display();
  return 0;
}