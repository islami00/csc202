//! @file Example 2 calculate the grade of students using switch case
//! (Interesting serialisation via integer division)

#include <iostream>
using namespace std;
#include <lib.h>
int main() {
  int score;
  char grade;

  // Take scpre
  cout << "Enter score: ";
  cin >> score;
  // Check validate
  if (score < 0 || score > 100) {
    cout << "Invalid score";
    return -1;
  }
  // Check grade. This was a Really nice way of serialising grades, moved it.
  cout << "Grade= " << my_utils::find_grades(score) << endl;
  return 0;
}