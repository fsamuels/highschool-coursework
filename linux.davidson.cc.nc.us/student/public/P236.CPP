// Show that the same code can return three different results.
// showAward has three instances of the Guarded Action pattern.
#include <iostream.h> // For cout and endl
#include "string"   // For the string class

string musicAward(long int recordSales);  // Avoid CodeWarrior warnings

string musicAward(long int recordSales)
{ // pre: Argument < maximum long int (usually 2,147,483,647)
  // post: Return a message appropriate to record sales
  string result;
  
  if(recordSales < 500000)
    result = "--Sorry, no certification yet. Try more concerts.";
  if(recordSales >= 500000)
    result = "--Congrats, your music is certified gold.";
  if(recordSales >= 1000000)
    result = result + " It's also gone platinum!";

  return result;
}

int main()
{ // Test drive showAwards three times with different results
  cout << 123456 << musicAward( 123456) << endl;
  cout << 504123 << musicAward( 504123) << endl;
  cout << 3402394 << musicAward(3402394) << endl;

  return 0;
}