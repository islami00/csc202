#include "islgr_util.h"
#include "lib.h"
// err enum

class Circular : public my_utils::Queue {
 private:
 public:
  Circular(int els);
  // use err enum.
  int enqueue(int);
  int dequeue();
  bool isFull();
  bool isEmpty();
  int count();
};

void tests();
int main() {
  tests();
  return 0;
}
Circular::Circular(int els = 5) : Queue(els) {}
int Circular::enqueue(int element){

};

void tests() {
  Circular* q = new Circular();
  EXPECT_T(q->isEmpty());
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
