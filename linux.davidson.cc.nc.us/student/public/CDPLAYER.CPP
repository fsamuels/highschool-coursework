#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>   // for cin and cout. This code runs befor the UI
#include <ctype.h>     // for toupper
#include "string"    
 // using namespace std;

#include "cdplayer.h" // allows separate compilation
// #include "irdev"      // for class IRDEV and the assembler routine PlaySignal
#include "track"
#include "compfun"    // for clearScreen and causeApause

void cdPlayer::initKenwoodDP_M7740()
{
  char option;

  cout << "Note: You will be simulating no matter what you enter." << endl;
  cout << "Change this if you get the IR devices." << endl ;
  cout << "Test with actual CD player or the playlist?  <c/p>: ";
  cin >> option;
  option = toupper(option);

  MY_SIMULATING = true;

/*  
  // Either simulate or play real music
  if('P' == option)
  {
    MY_SIMULATING = true;
  }



  else
  {
    MY_SIMULATING = false;

    my_cdPlayer.LoadData("CD");          // Read the data from disk
  
    clearScreen();
    cout << "Cash-Less Jukebox Startup Procedure" << endl;
    cout << "===================================" << endl;
    cout << "\n   1. Even if its playing, turn OFF the Kenwood DP-M7740" << endl;
    causeApause();
    cout << "\n   2. Make sure the Kenwood DP-M7740 is turned off, then turn it ON." << endl;
    causeApause();
    cout << "\n   3. If necessary, turn the IR remote control device ON" << endl;
    causeApause();
    cout << "\n   4. Wait until the CD starts to play -- Is the  stereo on???" << endl;
    causeApause();
    cout << "\n   5. Music should be playing. Is it <y/n>: " ;

    do 
    {
      cin >> option;
      option = toupper(option);
    } while (option != 'Y' && option != 'N');

    if(option == 'N')
    {
      clearScreen();
      cout << "Try again" << endl; 
      exit(0);
    }
    else
    {
      my_cdPlayer.PlaySignal("P-Mode");  // Make sure my Kenwood is in play mode 
                                         // so it accepts up to 20 songs  
      clearScreen();
      cout << "\nThe Kenwood DP-M7740 should be playing the first song of the bottom tray." << endl;
      cout << "With this old CD player, only 20 songs can be played." << endl;
      cout << "\nIf the tracks play out at any time, the Kenwood CD player stops!" << endl;
      cout << "If this happens, somone will have to " << endl;
      cout << "   1. Shut down this program. " << endl;
      cout << "   2. Start this program again. " << endl;
      cout << "   3.  -- or buy a newer CD player -- 200 CD players accept new songs." << endl;
      cout << "\nDo you understand? <y/n>: " ;
      do 
      {
        cin >> option;
        option = toupper(option);
      }  while (option != 'Y' && option != 'N');
    
      if(option == 'N')
      {
        cout << "\n\nQuit the program and begin again" << endl;
        causeApause();
        exit(0);
      }
      else
      {
        cout << "\nCongratulations! Now select up to 20 tracks before the last selection stops" << endl;
        causeApause();
      } 
    }
  } // else that initializes the phyiscal CD player

*/

}

void cdPlayer::playTrack (const track & currentSelection)
{    
  if(MY_SIMULATING)
  {
    clearScreen();
    cout << "\nPretend to queue up CD# " << currentSelection.cdNumber() << " track# ";
    cout << currentSelection.trackNumber() << " titled '" << currentSelection.title() << "'." << endl;
    cout << "Playtime would be " << currentSelection.playTime() /60 <<  ":";
    if(currentSelection.playTime() % 60 < 10)
    {
      cout << "0";
    }
    cout << currentSelection.playTime() % 60 << endl;
    flush(cin);  // from compfun
    causeApause();
  }
//  else
//  { // Actually play the song
//    delay(12000000);   // loop 12 million times, to delay.
//
//    //TrayCodec returns P for 0, dOne, dTwo, dThree, dFour, dFive, or dSix
//    my_cdPlayer.PlaySignal( TrayCode( currentSelection.cdNumber() ).c_str() );
//
//    // select tracknumber on the most recent my_cdPlayer tray location
//    // Note: this only works when track numbers are less than 20)
//
//    if( currentSelection.trackNumber() >= 10 )
//    {
//      delay(8000000);
//      my_cdPlayer.PlaySignal("+Ten");
//      delay(8000000);
//      my_cdPlayer.PlaySignal( currentSelection.trackNumber() %  10);
//    }
//    else
//   {
//      delay(8000000);
//      my_cdPlayer.PlaySignal( currentSelection.trackNumber() );
//   }
//    // Send signal to play track # 0..9,  Note: +ten may have already been pushed
//  }

}

string cdPlayer::TrayCode(int cdNumber)
{ 
  
  char disk[8];

  switch (cdNumber) {
  case 0:
     sprintf(disk, "P");    // Select the bottom tray on a kenwod. The IR data lists 7 as P 
     break;
  case 1:
     sprintf(disk, "dOne");  // select disk one. "dOne" is the code in the data file
     break;
  case 2:
     sprintf(disk, "dTwo");
     break;
  case 3:
     sprintf(disk, "dThree");
     break;
  case 4:
     sprintf(disk, "dFour");
     break;
  case 5:
     sprintf(disk, "dFive");
     break;
  case 6:
     sprintf(disk, "dSix");
     break;
  default:
     fprintf(stderr, "Invalid disk number!");
     sprintf(disk, "Zero");
  break;
  }
  string result(disk);
  return result;
}

void cdPlayer::delay(long n)
{ // A phony delay that works on my 200 mhz pentium 
  int j;
  for(j = 0; j < n; j++)
    ;  
}
