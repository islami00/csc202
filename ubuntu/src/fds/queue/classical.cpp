#include "islgr_util.h"
#include "lib.h"
// shadow def from lib
class Classical : public my_utils::Queue {
 private:
 public:
  Classical(int el);
};

void tests();

int main() {
  tests();
  return 0;
}

Classical::Classical(int el = 5) : Queue(el) {}
void tests() {
  Classical* q = new Classical();
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
}