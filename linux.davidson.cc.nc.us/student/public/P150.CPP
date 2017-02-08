// The main function makes several calls to test a new function
#include <iostream.h>

const double MONTHLY_FEE = 5.00;

double serviceCharge(int checks, int ATMs); // Avoid Codewarrior Warning
double serviceCharge(int checks, int ATMs)
{ // pre: checks >= 0 and ATM >= 0
  // post: Return a banking fee based on local rules
  double result;
  result = 0.25 * checks + 0.10 * ATMs + MONTHLY_FEE;
  return result;
}

int main()
{ // Test drive serviceCharge // Sample problems:
  cout << serviceCharge(0, 0) << endl; // 5.00
  cout << serviceCharge(1, 0) << endl; // 5.25
  cout << serviceCharge(0, 1) << endl; // 5.10
  cout << serviceCharge(1, 1) << endl; // 5.35
  
  return 0;
}