#include <iostream>

using namespace std;
// Forward declaration of test two class:
// https://www.programiz.com/cpp-programming/friend-function-class
// ONly after forward declare does can function belong to both at once
class test2;
class test1 {
 private:
  int a;

 public:
  void geta() {
    cout << "Enter a value for a";
    cin >> a;
  }
  friend void compare(test1, test2);
};
class test2 {
  int b;

 public:
  void getb() {
    cout << "Enter a value for b";
    cin >> b;
  }
  // Remember, this is shorthand form of args
  friend void compare(test1, test2);
};
int main() {
  test1 try1;
  try1.geta();
  test2 try2;
  try2.getb();

  compare(try1, try2);
  return 0;
}
void compare(test1 yo, test2 yolo) {
  if (yo.a > yolo.b) {
    cout << "a is big\n";
    return;
  }
  if (yo.a == yolo.b) {
    cout << "They are equal\n";
    return;
  }
  cout << "b is big\n";
}