#include "button.h"
#include <iostream>
int button::increase() {
  count += 1;
  baseCount += 1;
  std::cout << "Count is: " << count << '\n';
  std::cout << "BaseCount is: " << baseCount << '\n';
  return count;
}

button::button() {
  count = 0;
  baseCount = 0;
}
button::~button() { std::cout << "Button gone" << '\n'; }