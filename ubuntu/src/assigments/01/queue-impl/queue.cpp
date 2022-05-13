#include <lib.h>

#include <iostream>
using namespace std;
int test();
int menuTest();
int get_input();
int main() { return test(); }
// #[test]
int menuTest() {
  my_utils::Queue q;
  int choice;
  do {
    choice = get_input();
    switch (choice) {
      case 1: {
        cout << "Enter an element to enqueue: ";
        int element;
        cin >> element;
        int res = q.enqueue(element);
        if (res == 1) {
          cout << "Error: Queue is full" << endl;
        }
        q.display();
        break;
      }
      case 2:
        try {
          int dequeued = q.dequeue();
          cout << "Dequeued: " << dequeued << "\n";
        } catch (std::logic_error e) {
          cout << "Error: " << e.what() << "\n";
        }
        q.display();
        break;
      case 3:
        q.display();
        break;
      case 4:
        cout << "Count: " << q.count() << "\n";
        break;
      case 5:
        cout << "Queue is ";
        if (q.isFull()) {
          cout << "full\n";
        } else {
          cout << "not full\n";
        }
        break;
      case 6:
        cout << "Queue is ";
        if (q.isEmpty()) {
          cout << "empty\n";
        } else {
          cout << "not empty\n";
        }
        break;
      case 7:
        cout << "Quitting ... \n";
        break;
      default:
        cout << "Error: Invalid choice\n";
    }
  } while (choice != 7);
  return 0;
}
int get_input() {
  // switch-case input corresponding to each method
  int input;
  cout << "1. Enqueue\n";
  cout << "2. Dequeue\n";
  cout << "3. Display\n";
  cout << "4. Count\n";
  cout << "5. isFull\n";
  cout << "6. isEmpty\n";
  cout << "7. Quit\n";
  cout << "Enter your choice: ";
  cin >> input;
  return input;
}
int test() {
  // We should be able to start an empty queue.
  my_utils::Queue q;
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