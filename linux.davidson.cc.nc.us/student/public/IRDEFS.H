// Defs for IR class, for PC IR control
//
// Chris Dodge

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
