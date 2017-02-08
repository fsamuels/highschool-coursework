#include "quizdata.h"
#include <fstream>
#include <iostream>
using namespace std;
#include "compfun"

quizData::quizData()
{
   // simple allow for a vector of quiazData objects
}

quizData::quizData(string filename)
{
  // Initialize my_data
  ifstream inFile(filename.c_str());
  if(!inFile)
  {
 	  cout << "**Error** opening file '" << filename << "'" << endl;
	  cout << "**Program terminated**";
	  exit(0);
  }
  else
  {
    int row, col;
	  inFile >> my_lastStudent >> my_lastQuiz;

    // The vector of vectors must be initialized in the constructor
    my_data.resize(my_lastStudent, my_lastQuiz);

	  // Initialize a my_lastStudent by my_lastQuiz two-dimensional vector
	  for(row = 0; row < my_lastStudent; row++)
    {
 	    for(col = 0; col < my_lastQuiz; col++)
      {
         inFile >> my_data[row][col];
      }
    }
  }
}

void quizData::display()
{
  int row =0, col = 0;

  decimals(cout, 1);

  cout << "\nQuiz data:" << endl;
  for(row = 0; row < my_lastStudent; row++)
  {
	 for(col = 0; col < my_lastQuiz; col++)
	 {
		cout.width(6);
		cout << my_data[row][col];
	 }
	 cout << endl;
  }
}

void quizData::studentStats()
{ // pre: my_lastQuiz > 1
  // An example of row by row processing
  double sum, lowest, average;
  int row, col;
  cout << endl;
  cout << "   Student        Average" << endl;
  cout << "   =======        =======" << endl;
  decimals(cout, 1);

  for(row = 0; row < my_lastStudent; row++)   // outer loop
  {
	 // Assume the first my_data is the lowest
	 lowest = my_data[row][0];
	 // Assign sum the value of the first my_data
	 sum = lowest;
	 // Process the remaining quizzes  (start with 2nd my_data in row)
	 for(col = 1; col < my_lastQuiz; col++)   // inner loop
	 {
		sum = sum + my_data[row][col];
		if(my_data[row][col] < lowest)
		  lowest = my_data[row][col];
	 } // End inner loop
	 // Drop the lowest my_data
	 sum = sum - lowest;

	 // Average is based on dropping lowest so Divide by one less than n
	 average = sum /(my_lastQuiz - 1);
	 cout.width(10);
	 cout << row;
	 cout.width(15);
	 cout << average << endl;
  } // End outer loop
}
