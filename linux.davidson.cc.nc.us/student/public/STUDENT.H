#ifndef STUDENT_H
#define STUDENT_H
// file name student.h

#include "string"  // for class string

class student {
public:
//--constructors
  student();
  // post: Initialize a student object with a name as "?name?", 
  //       0.0 credits, and 0.0 quality points 

  student(string initName, double initCredits, double initQualityPoints);
  // post: Initialize a student object with this 3 argument constructor
  //          student("Delaisio, Donna", 30.0, 120.0);  
  //       A straight A sophomore at one school

//--modifier
  void completedCourse(double credits, double numericGrade);
  // post: record a completed course by adding credits to my_credits
  //       and incrementing the qualityPoints by (credits * numericGrade)
  //          aStudent.recordCourse(4.0, 3.67)  // a 4 credit A- perhaps

//--accessors
  double GPA() const;
  // post: return the current grade point average as the accumulated 
  //       quality points divided by the total number of credits. 

  string standing() const;
  // post: use selection to return the current standing as either
  //       Freshman, Sophomore, Junior, or Senior.

  string name() const;
  // post: return the student's name

private:
  string my_name;
  double my_credits;  // Total credits completed
  double my_qualityPoints; // sum of credits multiplied by grades
};

#endif