// This program test the entire system as if anyone cold play as 
// many tracks as desired. At the time of this writing, the Kenwood 
// CD player can only store up to 7 CDs. The testing will be done with 
// six CDs stored in a 6 CD cartridge. To actually play the songs, 
// remove comment dealing with theCdPlayer.

#include <cctype>      // for tfoupper
#include <iostream>    // for cout and endl 
using namespace std;
#include "cdplayer"    // for class cdPlayer
#include "track"       // for class track
#include "cd"          // for class CD  
#include "cdcollec"    // for class cdCollection
#include "compfun"     // for causeApause() and clearScreen()

void show(CD & aCD)
{
  track aTrack;
  aCD.first();
  while(! aCD.isDone())
  {
    aTrack = aCD.currentItem();
    cout.width(2);
    cout << aTrack.trackNumber() << "  " << aTrack.title() << endl;
    aCD.next();
  }
}
  
int main()
{
  cdPlayer theCdPlayer;
  theCdPlayer.initKenwoodDP_M7740();
  // Until I get a new CD player, use this brand name.

  int cdNum, trackNum; 
  track currentSelection;
  char option;

  cdCollection theCdCollection;
  
  theCdCollection.initialize("cd.dat");
  CD aCD;  
  track aTrack;
  // Use a loop: for testing the CD player signals and delays only
  do {
    // clearScreen();
    // Iterate over all CDs in the cdCollection, just show artist and title
    theCdCollection.first();
    while( ! theCdCollection.isDone() )
    {
      aCD = theCdCollection.currentItem();
    
      // Let use choose a CD #
      cout.width(3);
      cout << aCD.cdNumber() << " " ;
      cout << aCD.artist()   << " " ;
      cout.width( 25 - aCD.artist().length() );
      cout <<  " " ;
      cout << aCD.title()    << endl;

      theCdCollection.next();
    }

    do {
      cout << "Enter CD number [1.." << theCdCollection.size() << "]: ";
      cin >> cdNum;
    } while (cdNum < 1 || cdNum > theCdCollection.size()); 

    //clearScreen();

    aCD = theCdCollection.getCD(cdNum) ;
    show(aCD);

    do {
      cout << "Enter track number [1.." << aCD.size() << "]: ";
      cin >> trackNum;
    } while (trackNum < 1 || trackNum > aCD.size() ); 

    aTrack = aCD.getTrack(trackNum);
    cout << "\nAbout to play" << endl;
    cout << "==============" << endl;
    cout << aCD.title() << " by " << aCD.artist() << endl;
    cout << " title: " << aTrack.title() << endl;
    cout << "  time: " << aTrack.playTime() << endl;
    cout << "   cd#: " << aTrack.cdNumber() << endl;
    cout << "track#: " << aTrack.trackNumber() << endl;

    theCdPlayer.playTrack( aTrack );

    cout << "\n        Another? <y/n>: ";
    cin >> option;

    option = toupper(option);
  } while (option != 'N');

  return 0;
}




