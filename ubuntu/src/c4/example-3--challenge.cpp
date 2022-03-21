//! @file print a gradeslist using if-else
#include <iostream>
using namespace std;
#include <lib.h>
/** 
 * @brief Alternative impl of find_grades using if-else flow. 
 * 
 * @return Returns a character or null if not a valid score */
char find_grades_if(int);
int main() { return 0; }
char find_grades_if(int score) {
  // Check
  // Return null
  if (score < 0 || score > 100) {
    return '\0';
  }
  char grade;
  switch (score / 10) {
    // By int division, equiv to score >= 90
    case 9:
      grade = 'A';
      break;
    // Score >= 80
    case 8:
      grade = 'B';
      break;
    // Score >= 70
    case 7:
      grade = 'C';
      break;
    // Score >= 60
    case 6:
      grade = 'D';
      break;
    // Score < 60
    default:
      grade = 'F';
      break;
  }
  return grade;
}