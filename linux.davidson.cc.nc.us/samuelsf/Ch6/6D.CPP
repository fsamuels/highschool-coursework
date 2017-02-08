/*
Forrest Samuels

3-11-99

This program makes you update the header and cpp files to add two new
class functions.
*/

# include <iostream>
# include "/student/csc134HA/samuelsf/Ch6/libbook"
using namespace std;

void main()
{ // test drive libraryBook

	libraryBook aBook("The Mythical Man Month", "Fred Brooks");
	cout << "Borrower at initialization: " << aBook.borrower()
	     << endl;
	cout << "Author: " << aBook.author() << endl;
	cout << "Title: " <<aBook.title() << endl;
}
