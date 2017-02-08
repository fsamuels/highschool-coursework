#include <iostream>
using namespace std;
#include "lendlist" // For lendableList, lendable, book, video, cdRom
#include "date"     // For Date::ToString

int main()
{
  lendableList lendList;
  lendable* lendPtr; // Store a reference to any lendable object
  string searchID = "QA76.2";
  if( lendList.getLendable(searchID, lendPtr) )
  {
    if( lendPtr->isAvailable() )
    { // Don't check out something that is unavailable
      cout << "Check out " << lendPtr->lendableID() << endl;
      lendPtr->checkSelfOut("Robert Evans");
    }
    else
    {
      cout << lendPtr->lendableID() << " unavailable" << endl;
    }
  }
  else
  {
    cout << searchID << " not found." << endl;
    cout << "Please recheck the lendable ID" << endl;
  }
 
  // Show updated status to indicate lendable list was in fact updated
  if(lendList.getLendable(searchID, lendPtr))
  {
    cout << "Borrower: " << lendPtr->borrowersID() << endl;
    cout << "Due: " << lendPtr->dueDate().ToString() << endl;
  }

  return 0;
}