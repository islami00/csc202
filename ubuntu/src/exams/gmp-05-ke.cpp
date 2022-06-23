#include <iostream>

using namespace std;

int main() {
  float ke, mass, velocity;
  cout << "Enter mass" << endl;
  cin >> mass;
  if (mass < 0) {
    cerr << "Mass must not be less than zero" << endl;
    exit(EXIT_FAILURE);
  }
  cout << "Enter velocity" << endl;
  cin >> velocity;
  ke = 0.5 * mass * velocity * velocity;
  cout << "Kinetic energy is: " << ke << endl;
  return 0;
}