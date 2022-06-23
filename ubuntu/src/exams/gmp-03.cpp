#include <iostream>

using namespace std;
float getN();
int main() {
  float average = getN();
  cout << "The average is: " << average << endl;
  return 0;
}

float getN() {
  float sum = 0;
  for (int i = 0; i < 5; i++) {
    cout << "Enter a number" << endl;
    int tmp;
    cin >> tmp;
    sum += tmp;
  }
  float avg = sum / 5.0;
  return avg;
}