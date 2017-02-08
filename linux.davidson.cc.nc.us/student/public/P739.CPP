// Declare, initialize, and display a triply subscripted vector
// object. The primitive C subscripted object is used here, but we
// could also use a vector of matrix objects to do the same thing.
#include <iostream.h>

int main()
{
  const int courses = 3;
  const int students = 11;
  const int quizzes = 6;
 
  int q[courses][students][quizzes];
  int c, row, col;
  for(c = 0; c < courses; c++)
  {
    for(row = 0; row < students; row++)
    {
      for(col = 0; col < quizzes; col++)
      { // Give each quiz a value using a meaningless formula
        q[c][col][row] = (col + 1) * (row + 2) + c + 25;
      }
    }
  }

  for(c = 0; c < courses; c++)
  {
    cout << endl;
    cout << "Course #" << c << endl;
    for(row = 0; row < students; row++)
    {
      for(col = 0; col < quizzes; col++)
      {
        cout.width(5);
        cout << q[c][col][row];
      }
    cout << endl;
    }
  }

  return 0;
}