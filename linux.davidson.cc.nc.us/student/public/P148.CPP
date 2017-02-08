// Call serviceCharge to determine a bank debit
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
{ // 0. Initialize objects
  int checks;
  int ATMs;
  double fee; // Stores the function return result

  // 1. Input
  cout << "Checks this month? ";
  cin >> checks;
  cout << "ATMs this month? ";
  cin >> ATMs;

  // 2. Process
  fee = serviceCharge(checks, ATMs);

  // 3. Output
  cout << "Fee = " << fee << endl;

  return 0;
}