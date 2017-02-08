// Illustrate another switch statement
#include <iostream.h> // For cout <<
#include <ctype.h> // For toupper(char) returns uppercase char

int main()
{
  char option = ' ';

  cout << "B)alance W)ithdraw D)eposit Q)uit: ";
  cin >> option;
  switch(toupper(option))
  {
    case 'B':
      cout << "Balance selected" << endl;
      break;
    case 'W':
      cout << "Withdraw selected" << endl;
      break;
    case 'D':
      cout << "Deposit selected" << endl;
      break;
    case 'Q':
      cout << "Quit selected" << endl;
      break;
    default:
      cout << "Invalid choice" << endl;
  } // End switch

  return 0;
}