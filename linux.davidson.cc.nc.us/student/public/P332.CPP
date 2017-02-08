// Use a do while loop that repeatedly asks for a valid option
#include <ctype.h> // For toupper
#include <iostream.h> // For cout, cin, and endl

char nextOption()
{ // post: Return an uppercase W, D, or Q
  char option = '?';
  do {
    cout << "W)ithdraw, D)eposit, or Q)uit: ";
    cin >> option;
    option = toupper(option);
  } while((option != 'W') &&
          (option != 'D') &&
          (option != 'Q'));
  return option;
}

int main()
{
  char choice = 'Q';

  do {
    choice = nextOption();
    // assert: choice is either 'Q', 'W', or 'D'
    if('W' == choice)
      cout << "\nValid entry--process W\n" << endl;
    if('D' == choice)
      cout << "\nValid entry--process D\n" << endl;
    if('Q' == choice)
      cout << "\nHave a nice whatever :)" << endl;
  } while ( choice != 'Q' );

  return 0;
}