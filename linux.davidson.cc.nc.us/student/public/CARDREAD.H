#ifndef CARDREAD_H
#define CARDREAD_H

class cardReader {
public:
  studentIdType getStudentID();  
  bool isCardSwiped();
private:  
  studentIdType my_studentID;
};

#endif
