// $Id: irutils.h_v 1.1 1994/06/09 20:57:37 chris Exp chris $

// Utilities for programs using the IR remote controller
// This class automatically loaeds the data and allows
// easy calling of the various signals.

// Chris Dodge - May 1994

// Defs for IR class, for PC IR control
//
// Chris Dodge

#ifndef IRDEV_H
#define IRDEV_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
// Chris Dodges irdefs.h file

#define TRUE 1
#define FALSE 0

#define SIZE 30000               // Size of signal data array
#define CLKTICK 0X1C             // Clock tick interrupt

#define SIGLEN 250  // Maximum signal length
#define SIGNO 34    // Number of signals for a device that can be held
#define SAMPLEFREQ 100000 // Frequency at which the signal is sampled

// Structures for holding signal data
struct DeviceData{
  char    Name[8];             // Device name
  float   Clock;               // Basic timing speed of signal
  int     Bias;                // Unevenness in hi/low signal lengths
  int     SignalNo;            // Number of signals
  int     SignalLen;           // Length of signal (bytes)
  int     Repeat;              // No of times the signal is played
  int     Pause;               // Pause in between signal repeats
};

struct SigDat {
  char   Name[9];              // Signal name
  char   data[SIGLEN];         // Signal data
};

class IRDEV {
private:
  DeviceData DeviceDat;
  SigDat SigData[SIGNO];
  int  ReadData(char*, DeviceData*, SigDat[]); // Reaeds data for this device
  void CalcSignal(int, int, int);         // Calcs signal from data
public:
  void LoadData(char*);                   // Loaeds data from file
  int  SigCount();                        // Returns signal count
  void PlaySignal(const char*);           // Plays a signal
// MERCER CHANGE: It was this:  void PlaySignal(char*);                 // Plays a signal

  void PlaySignal(int);                   // Plays a signal (numeric)
};

#endif

