// File name: testlend.cpp
//
#include <iostream.h>
//using namespace std;

#define DebuggingLateFee // lendable.h now sets dueDate in the past
#include "lendable" // For the lendable, book, and video classes
#include "compfun" // For decimals(cout, 2)

void show(const lendable & aLendable)
{
  cout << "The lendable " << aLendable.lendableID();
  if(aLendable.isOverdue())
    cout << " is overdue. ";
  else
    cout << " is not overdue. ";

  cout << "Late fee = $" << aLendable.lateFee() << endl;
  cout << "Due date: " << aLendable.dueDate().ToString() << endl;
  if(aLendable.isAvailable())
    cout << "It is available. " << endl;
  else
    cout << "It is not available. " << aLendable.borrowersID()
         << " has it." << endl;
  cout << "---------------------------------------------" << endl;
}

int main()
{ // Test drive video and book
  decimals(cout, 2); // To show late fees nicely
  cout << "TEST BOOK: " << endl;
  book aBook("QA76.1M46", "Rick Mercer", "Computing Fun.");
  show(aBook);
  aBook.checkSelfOut("555-55-5555");
  show(aBook);
  aBook.checkSelfIn();
  show(aBook);
  cout << "\nTEST VIDEO: " << endl;
  video aVideo("MGM10023", "Spartacus");
  show(aVideo);
  aVideo.checkSelfOut("555-55-5555");
  show(aVideo);
  aVideo.checkSelfIn();
  show(aVideo);
 
  return 0;
}
