#include <iostream>
using namespace std;
int main() {
  // House: [addr,rent][]
  // In matr:  [5][2].
  int House[5][2] = {
      {128, 500}, 
      {204, 750}, 
      {601, 495}, 
      {609, 800}, 
      {612, 940},
  };
  int hn;
  do {
    cout << "Enter house number, or '-1' to quit" << endl;
    cin >> hn;
    bool isFound = false;
    int rent;
    int currentHn;
    // Find
    for (int i = 0; i < 5; i++) {
      currentHn = House[i][0];
      rent = House[i][1];
      if (hn == currentHn) {
        isFound = true;
        break;
      }
    }
    if (isFound) {
      cout << "Rent: $" << rent << endl;
    } else {
      cout << "House number: " << hn << " Not found" << endl;
    }
  } while (hn != -1);
  return 0;
}
