// ------------------------------------------------------------
// file name:  quizdata.h
// ------------------------------------------------------------
#ifndef QUIZDATA_H
#define QUIZDATA_H
#include <string>     // for class string
using namespace std;
#include "matrix"     // for class matrix

class quizData {
public:
  quizData();

  quizData(string filename);
  // post: initialize matrix using the filename

  void display();
  // post: Display the entire matrix 

  void studentStats();
  // post: Displays a row by row report of student's scores 

  void quizStats();
  // post: Displays a column by column report 

  double average();
  // post: returns the overall quiz average 

private:
  int my_lastStudent, my_lastQuiz;
  matrix <double> my_data;
}; 

#endif
