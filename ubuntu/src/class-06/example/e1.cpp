#include <iostream>

using namespace std;
class button {
 private:
  int count = 0;
  //   The data in the class is subject to same rules as regular vars.
  //   Initialise or you get garbage value;
  int baseCount;

 public:
  int increase() {
    count += 1;
    baseCount += 1;
    printf("Count is: %d\n", count);
    printf("BaseCount is: %d\n", baseCount);
    return count;
  }
};

int main() {
  button watashiNoEOne;

  watashiNoEOne.increase();
  watashiNoEOne.increase();
  watashiNoEOne.increase();
  watashiNoEOne.increase();
  watashiNoEOne.increase();
  watashiNoEOne.increase();
  watashiNoEOne.increase();
  return 0;
}