#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  for (int i = 1; i <= 1000; i++) {
    bool is30Div = (i % 30) == 0;
    if (is30Div) continue;
    bool is13Div = (i % 13) == 0;
    bool is15Div = (i % 15) == 0;
    bool is17Div = (i % 17) == 0;
    if (is13Div || is15Div || is17Div) {
      sum += i;
    }
  }
  cout << sum;
  return 0;
}