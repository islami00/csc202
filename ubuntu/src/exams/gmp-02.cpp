#include <iostream>
using namespace std;
int main() {
  char s[] = "man";
  int i;
  for (i = 0; s[i]; i++) {
    cout << "%c%c%c%c", s[i], *(s + i), *(i + s), i[s];
  }
}