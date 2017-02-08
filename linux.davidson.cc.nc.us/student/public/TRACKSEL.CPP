#include <iostream.h>  // for cout and endl 
#include "compfun"
#include "tracksel.h"

const int maxCdsToShow = 10;

// Some free non-member functions that makes things a bit easier (implemented below)
void showTitle();
// Display title every maxCdsToShow times

void showTracks(CD & aCD);
// Shows all track in any one CD

// The trackSelector member functions 

void trackSelector::message(string theMessage)
{
  clearScreen();
  cout << "----------------------------------------------------" << endl;
  cout << theMessage << endl;
  cout << "----------------------------------------------------" << endl;
  causeApause();
}

track trackSelector::getTrack(cdCollection & theCdCollection)
{
  CD aCD;  
  track aTrack;
  int cdNum;
  int trackNum;
  char option;
 
  // Get the user's selection
  do {
    clearScreen();
    // Iterate over all CDs in the cdCollection, just show artist and title
    theCdCollection.first();
    int n(0);

    showTitle();

    while( ! theCdCollection.isDone() )
    {
      aCD = theCdCollection.currentItem();
    
      // Let user choose the CD #
      cout.width(3);
      cout << aCD.cdNumber() << " " ;
      cout << aCD.artist()   << " " ;
      cout.width( 25 - aCD.artist().length() );
      cout <<  " " ;
      cout << aCD.title()    << endl;

      theCdCollection.next();
      n++;
      
      if( (n % maxCdsToShow == 0) && ( ! theCdCollection.isDone() ) )
      { // Pause and clear screen every maxCdsToShow times, unless all CDs have been shown
        cout << "\nThere are More CDs to choose from" << endl;
        cout << "\nContinue? <y/n>" << endl;
        cin >> option;
        option = toupper(option);
        if (option == 'N')
           break;
        causeApause();
        clearScreen();
        showTitle();
      }
    }

    do {
      cout << "\nEnter CD number [1.." << theCdCollection.size() << "]: ";
      cin >> cdNum;
    } while (cdNum < 1 || cdNum > theCdCollection.size()); 

    clearScreen();

    aCD = theCdCollection.getCD(cdNum) ;

    showTracks(aCD);  

    do {
      cout << "\nEnter track number [1.." << aCD.size() << "]: ";
      cin >> trackNum;
    } while (trackNum < 1 || trackNum > aCD.size() ); 

    aTrack = aCD.getTrack(trackNum);
    cout << "\nYou have selected: " << endl;
    cout << "=================" << endl;
    cout << aTrack.title() << "  " 
         << aTrack.playTime() /60 <<  ":";
    if(aTrack.playTime() % 60 < 10)
    {
      cout << "0";
    }
    cout << aTrack.playTime() % 60 << endl;
    cout << "from \"" << aCD.title() << "\" by " << aCD.artist() << endl;
    
    cout << "\n        Confirm? <y/n>: ";
    cin >> option;
    option = toupper(option);
  } while (option != 'Y');

  return aTrack;
}

void showTracks(CD & aCD)
{
  track aTrack;
  aCD.first();
  
  cout << "Pick you track number from '"; 
  cout << aCD.title() << "' by " << aCD.artist() << endl;

  cout << "\nTrack# Song Title " << endl;
  cout << "====== =======================" << endl;
  while(! aCD.isDone())
  {
    aTrack = aCD.currentItem();
    cout.width(6);
    cout << aTrack.trackNumber() << "  " << aTrack.title() << " ";
    cout << aTrack.playTime() /60 <<  ":";
    if(aTrack.playTime() % 60 < 10)
    {
      cout << "0";
    }
    cout << aTrack.playTime() % 60 << endl;
    aCD.next();
  }
}

void showTitle()
{
  cout << "Remember your choice of CD number (to the left)\n" << endl;
  cout << "CD# Artist                   Title" << endl;
  cout << "=== =======================  ==========================" << endl;
}
