// This program uses blocks for both the true and false parts. The
// block makes it possible to treat many statements as one.
#include <iostream.h>

int main()
{
  double GPA = 0.0;
  double margin = 0.0; // How far from dean's list cut-off

  cout << "Enter GPA: ";
  cin >> GPA;

  if(GPA >= 3.5)
  { // True part contains more than one statement in this block
    cout << "Congratulations, you are on the dean's list." << endl;
    margin = GPA - 3.5;
    cout << "You made it by " << margin << " points." << endl;
  }
  else
  { // False part contains more than one statement in this block
    cout << "Sorry, you are not on the dean's list." << endl;
    margin = 3.5 - GPA;
    cout << "You missed it by " << margin << " points." << endl;
  }

  return 0;
}