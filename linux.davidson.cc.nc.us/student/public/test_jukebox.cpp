#include "jukebox"  // for class jukebox 
#include "compfun" // causeApause();

int main()     
{ 
  jukeBox theJukeBox; 

  while(theJukeBox.isRunning())  
  {
     theJukeBox.processOneUser();
  }

  return 0;

 causeApause();
}

  
