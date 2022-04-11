#include <iostream>

using namespace std;

int main() {
  class student {
   private:
    /* data */
   public:
    void getData() { printf("Data"); }
  };
  student watashi;
  watashi.getData();

  return 0;
}