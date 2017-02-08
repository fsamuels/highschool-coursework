// This program computes and displays a final course grade as a
// weighted average after the user enters the appropriate input

// Use .h if you're having trouble with an older non-standard compiler
#include <iostream.h> // For cin, cout, and endl

// The files in NonStandardBookCode will have the next line removed

//using namespace std; // This allows programmers to write cin and cout
// instead of std::cin and std::cout

int main()
{
  // Declare and initialize the numeric objects
  double test1 = 0.0;
  double test2 = 0.0;
  double finalExam = 0.0;
  double courseGrade = 0.0;
  
  // 1. Obtain values for test1, test2, and finalExam from the user
  cout << "Enter first test: ";
  cin >> test1; // Modify test1's state with input
  cout << "Enter second test: ";
  cin >> test2;
  cout << "Enter final exam: ";
  cin >> finalExam;

  // 2. Process (25% of test1) + (25% of test2) + (50% of finalExam)
    courseGrade = (0.25 * test1) + (0.25 * test2) + (0.50 * finalExam);
  
  // 3. Display the value of courseGrade
  cout << "Course Grade: " << courseGrade << "%" << endl;
  
  return 0;
}