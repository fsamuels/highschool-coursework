#include "cardread.h"

studentIdType cardReader::getStudentID()
{ // Note: This implementation uses the keyboard.
  //       Change this for cardreader input.
  cin >> my_studentID;
  return my_studentID;
}

bool cardReader::isCardSwiped()
{ // Note: This implementation uses the keyboard
  //       Change this for cardreader input.
//  clearScreen();
  cout << "Enter your student ID: ";
  if(cin.peek())   // returns true if something is in input--Input is not removed form cin
    return true; 
  else
    return false;
}
