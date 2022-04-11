//! @file This illustrates data independence of instances and more on how
//! classes work. I feel like I'm ready for stacks!
#include <button.h>

#include <iostream>
using namespace std;
int main() {
  button watashiNoEOne;
  button watashiNoETwo;

  watashiNoEOne.increase();
  watashiNoETwo.increase();
  watashiNoEOne.increase();
  watashiNoETwo.increase();
  watashiNoEOne.increase();
  watashiNoETwo.increase();
  watashiNoEOne.increase();
  return 0;
}