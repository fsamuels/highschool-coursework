// Send every possible message to a libraryBook object
#include <iostream.h> // For cout
#include "libbook" // For the libraryBook class

int main()
{
  libraryBook aBook("Little Drummer Girl", "John LeCarre");
  cout << aBook.borrower() << endl;
  aBook.borrowBook("Chris Miller");
  cout << aBook.borrower() << endl;
  aBook.returnBook();
  cout << aBook.borrower() << endl;

  return 0;
}