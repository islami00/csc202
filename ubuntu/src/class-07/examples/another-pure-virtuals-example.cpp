#include <iostream>

using namespace std;
class Shape {
public:
  virtual void getArea() = 0; // pure virtual function
};
class Circle : public Shape {
public:
  void getArea() // overritten the base function
  {
    cout << "Enter Circle radius" << endl;
    int r;
    cin >> r;
    cout << "Area of circle is:" << (3.14 * r * r);
  }
};
class Rectangle : public Shape {
public:
  void getArea() // overritten the base function
  {
    cout << "Enter length and breadth to calculate area of Rectangle " << endl;
    int l, b;
    cin >> l >> b;
    cout << "Area of Rectangle is:" << (l * b);
  }
};
int main() {
  Circle c1;
  c1.getArea();
  Rectangle r1;
  r1.getArea();
}