#include <iostream>

using namespace std;

void display(int);
void display(double);
void display(int, double);

int main() {
  int a = 1;
  double b = 2;
  display(a);
  display(b);
  display(a, b);

  return 0;
}
// Overloads.
void display(int a) { cout << "Integer number" << a; };
void display(double b) { cout << "double number" << b; };
void display(int a, double b) {
  cout << "Integer number" << a;
  cout << "Double number" << b;
};
