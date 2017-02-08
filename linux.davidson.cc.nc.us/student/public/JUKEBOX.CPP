#include "jukebox.h"  // for class jukeBox()
#include "compfun"    // for clearScreen()

jukeBox::jukeBox()
{
  cout << "Prepare to set up the Kenwood M7740" << endl;
  my_cdPlayer.initKenwoodDP_M7740();
}

void jukeBox::processOneUser()
{ // Do whatever is necessary to process one user request

  while ( ! my_cardReader.isCardSwiped() )
    ;  // do nothing

  my_currentStudent = my_cardReader.getStudentID();
  
  // need to get studentCollection before this is completed.
  // For now, just proceed as if every student is valid
  
  my_currentSelection = my_trackSelector.getTrack(my_cdCollection);
  
  my_cdPlayer.playTrack(my_currentSelection);
}

bool jukeBox::isRunning()
{ // true until jukeBox somehow detects that it is time to shut down
  
  char option;
  clearScreen();
  cout << "when charlie finishes student, " 
       << "I'll create a student with the magic password" << endl;
  cout << "Process another user request? <y/n>: ";
  cin >> option;
  option = toupper(option);
  return (option == 'Y');

  // Under construction: Perhaps we could use a student ID password.
  // Then this function could return like this:

  // return (currentStudent.ID() != SECRET_PASSWORD);
}

