/* Forrest Samuels
	CSC 134
	March 19, 1999
	7g.cpp

	This program will require me to add a bool data member to the
libraryBook class to find out if a book is available or not.

*/


#include "/student/csc234/leonard/c++/libbook"  
#include <iostream>  // for cout
using namespace std;

int main()
{
  libraryBook aBook("The Mythical Man Month", "Fred Brooks");

  if(aBook.isAvailable())
    cout << "Book is available" << endl;  

  aBook.borrowBook("Chris Miller");
                                         
  if(aBook.isAvailable())             
    cout << "ERROR: Something is wrong!" << endl;
  else 
	 cout << "Not available, " << aBook.borrower() << " has it" <<
endl;            

  aBook.returnBook();

  if(aBook.isAvailable())
	 cout << "Available again" << endl;
  else 
    cout << "ERROR: Something is wrong!" << endl;

  return 0;
}


