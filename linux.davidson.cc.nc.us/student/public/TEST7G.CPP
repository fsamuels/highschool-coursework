// file name: test7g.cpp
#include "libbook"   // for class libraryBook in libbok.h and the
                     // member function implementations in libbook.cpp
#include <iostream>  // for cout
// using namespace std;
#include "compfun"

int main()
{
  libraryBook aBook("The Mythical Man Month", "Fred Brooks");

  if(aBook.isAvailable())
    cout << "Book is available" << endl;

  aBook.borrowBook("Chris Miller");

  if(aBook.isAvailable())             
    cout << "ERROR: Something is wrong!" << endl;
  else 
	 cout << "Not available, " << aBook.borrower() << " has it" << endl;            

  aBook.returnBook();

  if(aBook.isAvailable())
	 cout << "Available again" << endl;
  else
    cout << "ERROR: Something is wrong!" << endl;

  causeApause();

  return 0;
}
