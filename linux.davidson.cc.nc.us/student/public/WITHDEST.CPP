#include "withdest.h"
#include <iostream.h>  // for cout
#include <string.h>  // for strlen and strcpy 

withDestructor::withDestructor(char* initText)
{
  my_chars = new char[strlen(initText) + 1];
  strcpy(my_chars, initText);
  cout << "In constructor, my_chars: '" << my_chars << "'" << endl;
}

withDestructor::~withDestructor()
{
  cout << "'" << my_chars << "' will be deleted by this destructor" << endl;
  delete [ ] my_chars;
  // Memory allocated with my_chars = new char[strlen(initText)+1];
  // has now been returned back to the free store. 
}
