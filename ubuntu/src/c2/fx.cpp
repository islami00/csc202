#include <iostream>

void displayMessage();
int main(int argc, char const *argv[]) {
  std::cout << "Hello from main." << std::endl;
  displayMessage();
  std::cout << "Back in main again." << std::endl;

  return 0;
}
// Lil fxs
void displayMessage() { std::cout << "LMAO"; }