#include <iostream>

using namespace std;

int main() {
  float count = 0;
  float score;
  float sum = 0;
  // Stop at tenth
  while (count < 10) {
    cout << "Enter a (positive) grade";
    cin >> score;
    if (score < 0) break;
    sum += score;
    count++;
  }
  cout << sum << " " << count;
  float av = sum / count;
  cout << "The average=" << av;
  return 0;
}