#include <string.h>

#include <iostream>
using namespace std;
// This is where I use a constructor
class e3Test {
 private:
  int car_number;
  char car_model;

 public:
  char* getData(char*);
  void showData();
  e3Test();
};

int main() {
  e3Test a;
  char full[20];
  //   Directly print
  puts(a.getData(full));
  //   Reading in scanf
  int num;
  char model;
  sscanf(full, "%d %c", &num, &model);
  printf("num: %d model: %c", num, model);

  return 0;
}
e3Test::e3Test() {
  car_number = 0;
  car_model = 'a';
}
void e3Test::showData() {
  printf("car number %d", car_number);
  printf("car number %c", car_model);
}
// Take in a template string and print members to it, returning a pointer to the
// same string for utility.
// The members here are printed with the format "%d %c"
char* e3Test::getData(char* place) {
  // Print char and int to full. Note: Don't use local var or it'll be deleted
  // on return
  // Also, sprintf clears stream before writing to it
  sprintf(place, "%d %c", car_number, car_model);

  return place;
}