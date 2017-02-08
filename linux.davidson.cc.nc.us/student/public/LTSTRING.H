//--------------------------------------------------------------------
// SPECIFICATION FILE: ltstring.h   Note: lt means lite. This is a subset
//
//  1. Defines class string as a proper subset of the standard string class
//  2. Prototypes the following overloaded operator functions
//     << output
//     >> input
//     < > >= <= (relational operators)
//     == != (equality operators)
//     +  (ops must be string objects or 1 string literal
//     getline(ostream, stringObject, terminator = '\n')
//
//--------------------------------------------------------------------
#ifndef LTSTRING_H      // Avoid duplicate compilation
#define LTSTRING_H
#include <iostream.h>  // for class istream and class ostream


class string {
public:
//--constructors:
  string();
  // post: String object is set to default null string as in string a;

  string(const char * initText);
  // post: Object is initialized using char* argument when constructed
  //       as string aStr ("Hall");

  string(char ch);
  // post: Object is initialized using char argument when constructed
  //       as string aStr ('A');

  // Copy constructor:
  string(const string & strObj);
  // post: Object is copied during argument/parameter associations
  //       and during a function return. Object is also initialized as 
  //       string anotherStr(aStr);

  ~string();
  // post: Memory for this string is returned back to the free store
  //       for use by other dynamic objects
  
//--assigment operators

  // Overload the assignment operator for string objects and char *
  string & operator = (const char * right);
  // post: The lvalue string object stores the string literal and
  //       the dynamic length of the expression to the right of =
  //       as in s1 = "A string literal"

  string & operator = (const string & rightValue);
  // post: The lvalue string object stores the string literal and
  //       the dynamic length of the expression to the right of =
  //       as in s1 = s2;

  // Concatenation operator:
  string & operator += (const string & right);
  // post: The right string object is appended to the
  //       string object on the left.

//-- accessors

  int find(const string & searchString) const;
  // post: Return the first occurence of searchString in this string
  //       If searchString is not found, return -1

  string substr(int begin, int end) const;
  // post: Return 
  
  int length() const;
  // post: The dynamic length of the string object is returned

  char * c_str() const;
  // post: The characters (char*) of the string object are returned.
  //       Use this as the argument like this:
  //         ifstream inFile(fileName.c_str()); // cannot use string arg.

//--modifiers

  string string::replace(int begin, int nChars, string newString);
  // pre:  begin <= this objects last character, the length of 
  //       newString equals nChars
  //       
  
//--access and modify with the subscript operator
  
  char & operator [] (int index);
  // post: Return a reference to one individual character like this
  //       sString[0] = 'A';   
  //       cout << aString[3];
  
  const char & operator [] (int index) const;
  // post: Return a reference to one individual character like this
  //       sString[0] = 'A';   
  //       cout << aString[3];
  //       This is the function that is called when a string is
  //       passed to a const parameter as in void foo(const string & s)
  //       Then, this woulf be illegal:  s[0] = 'A';  // error

private:
  int my_len;          // The length of any one object
  char * my_chars;  // A pointer to the characters of a string object
}; // End the string class declaration


//--------------------------------------------------------------------
// Allow easy input and output of strings for standard I/O (cin/cout)
// and simple file I/O with ifstream and ofstream objects only
//--------------------------------------------------------------------
ostream & operator << (ostream & os, const string & outputString);
istream & operator >> (istream & is, string & inputString);
istream & getline(istream & is, string & s, char sentinel = '\n');

//--------------------------------------------------------------------
//  Allow catenation and comparison of string objects
//--------------------------------------------------------------------
string operator + (const string & left, const string & right);
string operator + (const string & left, const char * right);
string operator + (const char * left, const string & right);

//--------------------------------------------------------------------
//  The overloaded relational and equality operator prototypes
//--------------------------------------------------------------------
bool operator  < (const string & left, const string & right);
bool operator <= (const string & left, const string & right);
bool operator  > (const string & left, const string & right);
bool operator >= (const string & left, const string & right);
bool operator == (const string & left, const string & right);
bool operator != (const string & left, const string & right);

#endif // LTSTRING
