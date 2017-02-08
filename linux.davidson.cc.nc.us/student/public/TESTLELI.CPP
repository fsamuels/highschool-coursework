// File name: testleli.cpp
#include <vector> 
//using namespace std;

#define DebuggingLateFee  // Sets due dates  2, 7, or 14 days ago
#include "lendable"       // for class lendable
#include "compfun"

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

   cout << "--------------------------------------------" << endl;
}

int main()
{
  decimals(cout, 2);  // to show late fees nicely

  vector<lendable*> item(10);
  item[0] = new book("BOOK 1", "Author One", "Title One");
  item[1] = new video ("VIDEO 1", "Video Title One");
  item[2] = new book("BOOK 2", "Book Two", "Title 2");
  item[3] = new video ("VIDEO 2", "Video Title Two");

  // Check out four lendables for borrower 444-44-4444 and show them
  int j;
  for(j = 0; j < 4; j++)
  {
    item[j]->checkSelfOut("444-44-4444");  // set due dates in the past
    show(*item[j]);
  }

  return 0;
}

