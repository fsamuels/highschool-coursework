// file name: test6d.cpp
#include "libbook" // for class libraryBook definition in libbook.h
                   // and member function implementations in libbook.cpp
#include <iostream>
// using namespace std;
#include "compfun" // causeApause();


int main()
{ // Test drive libraryBook
  libraryBook aBook("The Mythical Man Month", "Fred Brooks");

  cout << "borrower at initialization: " << aBook.borrower() << endl;
  cout << "Author: " << aBook.author() << endl;
  cout << "Title: " << aBook.title() << endl;

causeApause();
  return 0;
}
