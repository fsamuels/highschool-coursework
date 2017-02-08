// Initialize a vector of bankAccount objects through file input
#include <vector>    // For the vector<CLASS> class
#include <fstream>   // For the ifstream class
#include <iostream>  // For cout and endl
#include <string>    // For the string class
using namespace std;
#include "baccount"  // For the bankAccount class
#include "compfun"   // For decimals(cout, 2)

int main()
{
  string fileName("bank.dat");
  ifstream inFile(fileName.c_str());

  if(! inFile)
  {
    cout << "**Error** " << fileName << " was not found" << endl;
  }
  else
  {
    vector <bankAccount> account(20);
    string name;
    double balance = 0.0;
    int numberOfAccounts = 0;
    int j;

    while( (inFile >> name >> balance) &&
         (  numberOfAccounts < account.capacity()) )
    { // assert: name and balance successfully input from inFile and
      // vector can store one more bankAccount
      account[numberOfAccounts] = bankAccount(name, balance);
      numberOfAccounts++;
    }
    // Antibugging tip: Verify that a vector is properly initialized!
    // numberOfAccounts is very important as is data stored at each vector
    // element. First output numberOfAccounts and display each element in
    // vector before going on.
    cout << "Number of accounts on file: " << numberOfAccounts << endl;
    cout << endl;
    cout << "The accounts" << endl;
    cout << "===========================" << endl;
    decimals(cout, 2);
    for(j = 0; j < numberOfAccounts; j++)
    {
      cout.width(2);
      cout << j << ". ";
      cout << account[j].name();
      // Pad blanks so balances line up at the decimal point
      cout.width(12 - account[j].name().length());
      cout << " ";
      cout.width(10);
      cout << account[j].balance() << endl;
    }
  } // End else
 
  return 0;
}
