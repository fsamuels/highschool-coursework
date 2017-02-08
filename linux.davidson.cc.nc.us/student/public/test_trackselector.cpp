// Send a getTrack message to the trackSelector object, which does a lot.
#include "tracksel"
#include "cdcollec"
#include "compfun"

int main()
{
  track aTrack;
  
  // Initialize the CD collection needed by getTrack
  cdCollection theCdCollection;
  trackSelector my_trackSelector;
 
  aTrack = my_trackSelector.getTrack(theCdCollection);
 
  cout << "You selected " << aTrack.title() << endl;

  causeApause();
  
  return 0;
}

