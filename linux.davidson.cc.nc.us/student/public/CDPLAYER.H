// file: my_cdPlayer.h
// class my_cdPlayer
// This class is a wrapper for Chris Dodge's class IRDEV and other utilities
#ifndef CDPLAYER_H
#define CDPLAYER_H
// #include "irdev"    // for class IRDEV and the assembler routine PlaySignal
#include "track"    // for class track

class cdPlayer {
public:
  void initKenwoodDP_M7740();
  //  Because of the idiosynchories of this old CD player, for now
  //  I think I want to have a separate named as the CD player.
  //  This initialization won't work on other brands (or would not be appropriate)
  //  This could eventually develop into an instance of the factory pattern.
  //  The initialization occurs at runtime. Then the same program could handle
  //  different brands of CD players.  
  
  void playTrack (const track & currentSelection);
  // Plays the a track using the CD# and track# on that CD

private:
  bool MY_SIMULATING;
//  IRDEV my_cdPlayer;   // IRDEV written by Chris Dodge
  string TrayCode(int cdNumber);
  void delay(long n);
};

#endif


