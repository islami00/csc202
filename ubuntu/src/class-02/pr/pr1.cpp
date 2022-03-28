#include <iostream>
void showDollars(double);
using namespace std;
int main() {
  double payRate, hoursWorked, wages;
  cout << "How many hours have you worked? ";
  cin >> hoursWorked;
  cout << "what is your hourly pay rate? ";
  cin >> payRate;
  wages = hoursWorked * payRate;
  showDollars(wages);
  return 0;
}

void showDollars(double cal) { cout << "The worked wage is: " << cal << '\n'; }