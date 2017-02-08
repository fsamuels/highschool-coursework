// Illustrate the flexibility offered by Alternative Action
#include <iostream.h>
#include "compfun" // For round(x, n)

int main()
{
  double pay = 0.0;
  double rate = 0.0;
  double hours = 0.0;
 
  cout << "Enter hours worked and rate of pay: ";
  cin >> hours >> rate;

  if(hours <= 40.0)
    pay = hours * rate; // True part
  else
    pay = (40 * rate) + (hours - 40) * 1.5 * rate; // False part
 
  pay = round(pay, 2);
  cout << "pay " << pay << endl;

  return 0;
}