#include "islgr_util.h"
#include "lib.h"
// err enum
//  could refactor fxs to return result tuple. [data,err]. and detect err if
//  err>=0. Result ref would be passed in and returned, populated.
// for now, negative is err
enum Errs { OVERFLOW = -2, UNDERFLOW };
class Circular : public my_utils::Queue {
 private:
 public:
  Circular(int els);
  // use err enum.
  int enqueue(int);
  int dequeue();
  bool isFull();
};

void tests();
int main() {
  tests();
  return 0;
}
Circular::Circular(int els = 5) : Queue(els) {}
int Circular::enqueue(int element){
  if (isFull()) {
    return Errs::OVERFLOW;
  }
  // first el.
  if (isEmpty()) {
    front = 0;
  }
  // circ.
  end = (end + 1) % QUEUE_SIZE;
  elements[end] = element;
};
int Circular::dequeue() {
  if (isEmpty()) {
    return Errs::UNDERFLOW;
  }
  int dequeued = elements[front];
  // reset.
  if (count() == 1) {
    front = end = -1;
  } else {
    // circ
    front = (front + 1) % QUEUE_SIZE;
  }
  return dequeued;
}
bool Circular::isFull() {
  // initial isFull
  if (front == 0 && end == (QUEUE_SIZE - 1)) {
    return true;
  }
  // isFull condition after moving end. if end circles back to behind front
  else {
    return (front == end + 1);
  }
}
void tests() {
  Circular* q = new Circular();
  EXPECT_T(q->isEmpty());
  EXPECT_T(q->dequeue() == Errs::UNDERFLOW);
  EXPECT_T(q->count() == 0);
  q->display();
  // add els.
  q->enqueue(5);
  EXPECT_T(q->count() == 1);
  q->display();
  EXPECT_T(q->dequeue() == 5);
  // fill up
  for (int i = 0; i < 5; i++) {
    q->enqueue(i + 1);
  }
  EXPECT_T(q->isFull());
  EXPECT_T(q->enqueue(12) == Errs::OVERFLOW);
  q->display();
  EXPECT_T(q->peek() == 1);
  // dequeue full
  for (int i = 4; i > 0; i--) {
    q->dequeue();
    EXPECT_T(q->count() == i);
    EXPECT_T(!q->isFull());
  }
  q->dequeue();
  EXPECT_T(q->count() == 0);
  EXPECT_T(q->isEmpty());
};
