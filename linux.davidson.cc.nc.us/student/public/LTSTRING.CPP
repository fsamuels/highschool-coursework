//----------------------------------------------------------------------
// IMPLEMENTATION file ltstring.cpp
//
//  Implements: class string
//----------------------------------------------------------------------
#include <string.h>    // for strlen and strcpy
#include <stdlib.h>    // for exit
#include <iostream.h>  // for class istream and class ostream

//--constructors

string::string()
{ // Initialize a string object as a null string in string a;
  my_len = 0;
  my_chars = new char[1];
  my_chars[0] = 0;    // Store the null char into the 
                      // first byte pointed to by my_chars
}

string::string(const char * initText)
{ // Initialize string objects as:
  //   string strVar ("Initial string");
  //   string strVar = "Initial string";
  my_len = strlen(initText);        // Actual length without '\0'
  my_chars = new char[my_len + 1];  // Allocate memory + 1 for '\0'
  strcpy(my_chars, initText);       // Let my_chars point to initText
}

string::string(char ch)
{ // Initialize string objects as:
  //   string strVar ('A');
  my_len = 1;
  my_chars = new char[2];            // Allocate memory + 1 for '\0'
  my_chars[0] = ch;
  my_chars[1] = '\0';
}

string::string(const string & source)
{ // This is the copy constructor which allows string b(a);
  my_len = source.my_len;
  my_chars = new char[my_len + 1];   // Allocate memory.
  strcpy(my_chars, source.my_chars); // Let my_chars point to the chars
                                     // of the copied object.
}

//--destructor

string::~string()
{ // Deallocate memory to avoid exhausting the free store
  delete [] my_chars;
}

//--accessors 

int string::length() const
{
  return my_len;
}

char * string::c_str() const
{
  return my_chars;
}

string string::substr(int pos, int n) const 
{
  if(pos >= this->my_len)
	 return "";

  string temp;
  for(int j = pos; j < (signed)strlen(this->my_chars) && n > 0; j++)
  {
	 temp += this->my_chars[j];
	 n--;
  }
  temp += '\0';
  return temp;
}

int string::find(const string & searchString) const
{
	int len(searchString.length());
   int thisObjectsLen(this->length());

   if(len > thisObjectsLen)
   {
	   return -1;
   }

   for(int j = 0; j <= thisObjectsLen - len; j++)
   {
	   if(searchString == this->substr(j, len))
		   return j; 
   }
   return -1;
}

//--modifiers

string string::replace( int begin, int nChars, string newString ) 
{ 
  if( nChars != newString.length() || begin >= this->length() )
	  return *this;
  int k(0);
  for(int j = begin; j < begin + nChars; j++)
  {
	  this->my_chars[j] = newString[k];
	  k++;
  }
  return *this;
}

//--assignment operators

string & string::operator = (const string & right)
{
  // Skip copying in statements like this: aString = aString;
  if (this != (&right) )
  {
    delete [] my_chars;   // Deallocate memory of old string object
    my_len = right.my_len;
    my_chars = new char[my_len + 1];
    strcpy(my_chars, right.my_chars);
  }
  return *this;
}

string & string::operator = (const char * rightValue)
{
  delete [] my_chars;     // Deallocate memory for the lValue object
  my_len = strlen(rightValue);
  my_chars = new char[my_len + 1];
  strcpy(my_chars, rightValue);
  return *this;
}

string & string::operator += (const string & right)
{ // Concatenation
  int combinedLength = this->my_len + right.my_len;
  // Allocate enough memory for both operands.
  char* temp = new char[combinedLength + 1];
  strcpy(temp, my_chars);         // 1. Create the 
  strcat(temp, right.my_chars);   //    new string
  delete [] my_chars;             // 2. Deallocate unneeded memory
  // 3. Point my_chars to the same memory as temp
  my_chars = temp;                // 4. Create and return
  my_len = combinedLength;        //    this newly
  return *this;                   //    created object
}

char & string::operator [] (int index)
{
  if((index < 0) || (index >= my_len))
  {
    if(my_len == 0)
    {
      cout << "\n**Error** Can't subscript an empty string" << endl;
    }
    else
    {
      cout << "\n**Error** For string object \"" << my_chars
           << "\", subscript [" << index << "] is out of range. " << endl;
        cout << "Subscript must be in the range of 0.." << (my_len-1) << endl;
    }
    cout << "Program terminated..." << endl;
    exit(0);
  }
  return my_chars[index];
}

const char & string::operator [] (int index) const
{
  if((index < 0) || (index >= my_len))
  {
    if(my_len == 0)
    {
      cout << "\n**Error** Can't subscript an empty string" << endl;
    }
    else
    {
      cout << "\n**Error** For string object \"" << my_chars
           << "\", subscript [" << index << "] is out of range. " << endl;
        cout << "Subscript must be in the range of 0.." << (my_len-1) << endl;
    }
    cout << "Program terminated..." << endl;
    exit(0);
  }
  return my_chars[index];
}

//--auxillary functions (non member functions avaialable for strings

ostream & operator << (ostream & os, const string & outputString)
{
  os << outputString.c_str(); // Insert characters to output stream.
  return os;
}

istream & operator >> (istream & is, string & inputString)
{
  char temp[128];  // Allow a very large input string
  is >> temp;      // Read chars up to first whitespace.
  inputString = string(temp); // Alter argument to right of >>
  return is;
}

istream & getline(istream & is, string & inputString, char sentinel)
{  // default argument specified in ltstring.h is  char sentinel = '\n'
  char temp[128];
  is.getline(temp, 128, sentinel);
  inputString = temp;
  return is;
}

string operator + (const string & left, const string & right)
{ // concatenation such as strVar + strVar
  string temp(left);   // Create new object with left operand.
  temp += right;       // Use the existing operation to create
  return temp;         // one string from two string operands.
}

string operator + (const string & left, const char * right)
{ // Concatenate as strVar + "a string";  // constant on right
  string temp(left);
  temp += right;
  return temp;
}

string operator + (const char * left, const string & right)
{ // Concatenation such as "a string" + strVar; // constant on left
  string temp;
  temp = left;
  temp += right;
  return temp;
}

bool operator < (const string & left, const string & right)
{
  return   (strcmp(left.c_str(), right.c_str())  < 0);
}

bool operator <= (const string & left, const string & right)
{
  return ! (strcmp(left.c_str(), right.c_str())  > 0);
}

bool operator > (const string & left, const string & right)
{
  return   (strcmp(left.c_str(), right.c_str())  > 0);
}

bool operator >= (const string & left, const string & right)
{
  return ! (strcmp(left.c_str(), right.c_str())  < 0);
}

bool operator == (const string & left, const string & right)
{
  return  (strcmp(left.c_str(), right.c_str()) == 0);
}

bool operator != (const string & left, const string & right)
{
  return  (strcmp(left.c_str(), right.c_str()) != 0);
}
