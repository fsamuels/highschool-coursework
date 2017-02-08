#include "cdcollec" // For the CD, track, and cdCollection classes



void showOneCD(CD & aCD)
{ // post: Show titles of all the tracks on aCDo
  track aTrack;
  for( aCD.first(); ! aCD.isDone(); aCD.next() )
  {
    aTrack = aCD.currentItem();
    cout << aTrack.title() << endl;
  }
}

int main()
{
  cdCollection theCDs;
  CD aCD;
  for( theCDs.first(); ! theCDs.isDone(); theCDs.next() )
  {
    aCD = theCDs.currentItem();
cout << aCD.artist() << "1111" << aCD.title() << "2222" << aCD.artist() 
     << "3333" 
         << aCD.artist() << "4444" << endl;
   showOneCD(aCD);
  }

  return 0;
}
