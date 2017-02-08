#include <iostream.h>   // 1  File name: getline.cpp
#include <fstream.h>    // 2
#include "string"     // 3
// using namespace std;  // 4
//  	                     
int main()            // 6
{                     // 7
  string aLine;
  ifstream inFile("p356.cpp");  // This file
  int lineCount = 0;
//
  while( getline(inFile, aLine) )
  {
	 lineCount++;      // 14
  }
//
  cout << "Lines in p356.cpp: " << lineCount << endl;
  return 0;
}                     // 19
