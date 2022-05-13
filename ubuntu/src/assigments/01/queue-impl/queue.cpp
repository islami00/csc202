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
  int count();
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
bool Queue::isFull() {
  if (end == (QUEUE_SIZE - 1)) return true;
  return false;
}
//   isEmpty
bool Queue::isEmpty() {
  if (front == -1) return true;
  return false;
}
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
//   count
int Queue::count() {
  // Cover case where end=front=-1
  if (isEmpty()) return 0;
  return end - front + 1;
}
int test();
int menuTest();
int get_input();
int main() { return menuTest(); }
// #[test]
int menuTest() {
  Queue q;
  int choice;
  do {
    choice = get_input();
    switch (choice) {
      case 1: {
        std::cout << "Enter an element to enqueue: ";
        int element;
        std::cin >> element;
        int res = q.enqueue(element);
        if (res == 1) {
          std::cout << "Error: Queue is full" << std::endl;
        }
        q.display();
        break;
      }
      case 2:
        try {
          int dequeued = q.dequeue();
          std::cout << "Dequeued: " << dequeued << "\n";
        } catch (std::logic_error e) {
          std::cout << "Error: " << e.what() << "\n";
        }
        q.display();
        break;
      case 3:
        q.display();
        break;
      case 4:
        std::cout << "Count: " << q.count() << "\n";
        break;
      case 5:
        std::cout << "Queue is ";
        if (q.isFull()) {
          std::cout << "full\n";
        } else {
          std::cout << "not full\n";
        }
        break;
      case 6:
        std::cout << "Queue is ";
        if (q.isEmpty()) {
          std::cout << "empty\n";
        } else {
          std::cout << "not empty\n";
        }
        break;
      case 7:
        std::cout << "Quitting ... \n";
        break;
      default:
        std::cout << "Error: Invalid choice\n";
    }
  } while (choice != 7);
  return 0;
}
int get_input() {
  // switch-case input corresponding to each method
  int input;
  std::cout << "1. Enqueue\n";
  std::cout << "2. Dequeue\n";
  std::cout << "3. Display\n";
  std::cout << "4. Count\n";
  std::cout << "5. isFull\n";
  std::cout << "6. isEmpty\n";
  std::cout << "7. Quit\n";
  std::cout << "Enter your choice: ";
  std::cin >> input;
  return input;
}
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
  //    Check how many items are in our queue
  int count = q.count();
  int enqueueRetCode = q.enqueue(4);
  bool enqueueOverflowGuardWorks = enqueueRetCode == 1;
  if (!q.isFull()) {
    throw std::logic_error("Is full failed on a full queue");
  }
  if (!enqueueOverflowGuardWorks) {
    throw std::logic_error("Enqueue does not handle overflow");
  }
  if (count != 3) {
    throw std::logic_error("Count failed on a queue with 3 items");
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