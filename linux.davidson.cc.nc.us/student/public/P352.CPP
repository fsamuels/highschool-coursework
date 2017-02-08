// This program reads data from an input file to alter one weeklyEmp
// object just long enough to produce a simple payroll report of the
// gross pay and the name of each employee in the disk file
#include <fstream.h> // For the ifstream class
#include <iostream.h> // For the ostream class and cout
#include "weekemp" // For the weeklyEmp class
#include "compfun" // For decimals(cout, 2)

int main()
{
  weeklyEmp anEmp;
  string fName, lName, name;
  double hours, rate;
  int exempts;
  string status;
  // Initialize an input stream with a disk file as the source
  ifstream inFile("payroll.dat");

  // Show error if the file "payroll.dat" is not found on the disk
  if(! inFile)
  {
    cout << "**Error opening file 'payroll.dat'" << endl;
  }
  else
  {
    cout.fill('*');
    decimals(cout, 2);
    cout << "Gross Pay Name" << endl;
    // Process data until end of file
    while(inFile >> hours >> rate >> exempts >> status >> fName >> lName)
    {
      name = lName + ", " + fName;
      anEmp = weeklyEmp(name, hours, rate, exempts, status);
      // Then call some class member functions
      cout.width(9);
      cout << anEmp.grossPay() << " " << anEmp.name() << endl;
    }
  }

  return 0;
}