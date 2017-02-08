// file name: irdev.cpp
// implements
//    class IRDEV
//    PlayIR, an assembler funcitonthat sends out the signals to the parallel port
#include "irdev.h"

int PlayIR(char* s, int n);         // ASM - Play signal back

// Global vars
char   Signal[SIZE];

// Loads data from disk for this device
void IRDEV::LoadData(char *DevName)
{
  if (ReadData(DevName, &DeviceDat, SigData)) 
  {
     fprintf(stderr, "ERROR: Can't initialize IRDEV class - data file not found!\n");
     exit(1);
  }
  return;
}

// Returns the no. of signals for this device
int IRDEV::SigCount()
{
        return DeviceDat.SignalNo;
}

// Plays the signal with the name passed
void IRDEV::PlaySignal(const char *Name)
{
  int i=0, j;

   // Search for this string in the signal names
   while (i<DeviceDat.SignalNo) 
   {
     if (strcmp(Name, SigData[i].Name) == 0) 
     {
       CalcSignal(0x0002, i, 0);
       j = PlayIR(Signal, SIZE);
       return;
     }
     i++;
   }

   // If get this far, signal not found.....
   fprintf(stderr, "Signal name %s not found in IRDEV::PlaySignal!\n", Name);
   return;
}

// Most devices have a numeric keypad....
// This routine plays the signal with the integer input value.
// Valid input range - 0..9
void IRDEV::PlaySignal(int no)
{
   int i=0;
   char Search[8];

   switch (no) {
     case 0:
       sprintf(Search, "Zero");
       break;
     case 1:
       sprintf(Search, "One");
       break;
     case 2:
       sprintf(Search, "Two");
       break;
     case 3:
       sprintf(Search, "Three");
       break;
     case 4:
       sprintf(Search, "Four");
       break;
     case 5:
       sprintf(Search, "Five");
       break;
     case 6:
       sprintf(Search, "Six");
       break;
     case 7:
       sprintf(Search, "Seven");
       break;
     case 8:
       sprintf(Search, "Eight");
       break;
     case 9:
       sprintf(Search, "Nine");
       break;
     default:
       fprintf(stderr, "Invalid param to LookupSignalNo!");
       sprintf(Search, "Zero");
       return;
     break;
   }

   PlaySignal(Search);
   return;
}


// Calculate signal from file data. No = Signal no.
// SO = Starting offset (for alignment)
void IRDEV::CalcSignal(int Mask, int No, int SO)
{
   float NoCounts;      // No. of counts in Sig array per IR up or down
   int Offset;          // No. of counts so far thru array
   int i, j, r, Val, Clear, From, To, SBias, EBias, PrevData;
   int Pos;

   NoCounts = SAMPLEFREQ/DeviceDat.Clock;
   Clear = 0xFF - Mask;
   PrevData = 0;

   // Loop over no. of signal repeats
   for (r=0; r<DeviceDat.Repeat; r++) 
   {
     // Loop over signal...
     for (i=0,Offset=0; i<SIGLEN; i++) 
     {
       Pos = i+(r*(SIGLEN+DeviceDat.Pause));

       // Determine whether a 1 is placed in array or not
       if (SigData[No].data[i] == '1') 
       {
          Val = 0;
       } 
       else 
       {
          Val = Mask;
       }

       // Work out biasing (ie. signal high/low irregularity)
       SBias = 0; 
       EBias = 0;
       if ((SigData[No].data[i]=='1')) 
       {
         EBias = DeviceDat.Bias;
       }

       if ((PrevData=='1') && (SigData[No].data[i]=='0')) 
       {
          SBias = DeviceDat.Bias;
       }

       From = (int)(NoCounts*Pos) + SO + SBias;
       To = (int)(NoCounts*(Pos+1)) + SO + EBias;
       if (From < 0) From = 0;
       if (To > SIZE) To = SIZE;
       if (From >= SIZE) return;

       for (j=From; j<To; j++) 
       {
         if (j<SIZE) 
          { // Check bouneds
             Signal[j] &= Clear;
             Signal[j] |= Val;
          }
       }

       PrevData = SigData[No].data[i];
     }
   
     // Fill up gap between this signal and the repeat with 0's
     for (i=j; i<(j+DeviceDat.Pause*NoCounts); i++)
     {
       if (i<SIZE) 
       {  // Check bouneds
         Signal[i] &= Clear;
       }
     }

     // Clear to end of signal array - removes the remains of old signals
     if (i<SIZE) 
     {
        for (j=i; j<SIZE; j++)
        {
           Signal[j] &= Clear;
        }
     }
   }

     return;
}

// Read the data from file for this particular device
// Dev = device name
// DeviceDat = structure to hold device params etc.
// SD = array to hold signal data for device
int IRDEV::ReadData(char* Dev, DeviceData *DeviceDat, SigDat SD[])
{
  FILE     *data;          // Pointer to data file
  char    line[250];       // Input line
  char    ThisDev[8];      // The device type of current line
  char    Info[16];        // Information type in current line
  char    ch;              // Temp var ..
  int     ChPos;           // Input character position counter
  char    type;            // The type of current word.
  int     NoFieleds;        // Number of fieleds read by scanf.
  int     SigCount;        // Number of signals read
//  char    N;               // Current signal name
//  char    S;               // Current signal
  int     ValidityCount;   // Checks have enogh parameters
//  int     I, i;
  int     i;
  float   F;

  if ((data = fopen("irinfo.dat", "r")) == NULL) 
  {
     fprintf(stderr, "*** Cannot open file IRINFO.DAT ***\n");
     return 1;
  }
        

  sprintf(DeviceDat->Name, Dev);
  SigCount = 0; ValidityCount = 0;

  // Read the data file.....
  do {
    // Read each line....
    ch = fgetc(data);
    ChPos = 0;
    type = 0;
    while ((ch!='\n')&&(ChPos<(SIGLEN+18))&&(ch!=EOF)) 
    {
      line[ChPos] = ch;
      ChPos++;
      ch = fgetc(data);
    }
    line[ChPos] = '\0';       // Null-terminate line.

    // Cancel previous values otherwise they stay on NULL lines
    // ie. they are not cleared by scanf
    sprintf(ThisDev, "\0");
    sprintf(Signal, "\0");

    // Extract the device type and info type
    NoFieleds = sscanf(line, "%s %s", ThisDev, Info);

    // If this device is of the wanted type, then read data
    // else ignore.
    if (!(strncmp(ThisDev, Dev, strlen(Dev)))) 
    {
      // Act on the word type option.
      if (!(strcmpi(Info, "Clock"))) 
      {
         NoFieleds = sscanf(line, "%s %s %f", ThisDev, Info, &F);
         DeviceDat->Clock = F;
         ValidityCount++;
      }

       if (!(strcmpi(Info, "Bias"))) 
       {
          NoFieleds = sscanf(line, "%s %s %d", ThisDev, Info, &DeviceDat->Bias);
          ValidityCount++;
       }

       if (!(strcmpi(Info, "SignalNo"))) 
       {
         NoFieleds = sscanf(line, "%s %s %d", ThisDev, Info, &DeviceDat->SignalNo);
         ValidityCount++;
       }

       if (!(strcmpi(Info, "SignalLen"))) 
       {
         NoFieleds = sscanf(line, "%s %s %d", ThisDev, Info, &DeviceDat->SignalLen);
         // Check length value
         if (DeviceDat->SignalLen > SIGLEN) 
         {
           fprintf(stderr, "*** ERROR: Required signal length too long ***");
           exit(1);
         }
         ValidityCount++;
       }

       if (!(strcmpi(Info, "Pause"))) 
       {
         NoFieleds = sscanf(line, "%s %s %d", ThisDev, Info, &DeviceDat->Pause);
         ValidityCount++;
       }

       if (!(strcmpi(Info, "Repeat"))) 
       {
          NoFieleds = sscanf(line, "%s %s %d", ThisDev, Info, &DeviceDat->Repeat);
          ValidityCount++;
       }

       if (!(strcmpi(Info, "Signal"))) 
       {
          if (SigCount == SIGNO) 
          {
             fprintf(stderr, "*** Error: Too many signals ***");
             printf("%s\n", line);
          }
          else 
          {
             NoFieleds = sscanf(line, "%s %s %s %s", ThisDev, Info, SD[SigCount].Name, SD[SigCount].data);
             // Check signal data length, if too short, fill with 0's
             if ( (strlen(SD[SigCount].data) < (size_t)DeviceDat->SignalLen) ) 
             {
               for (i=(strlen(SD[SigCount].data)-1); i<(DeviceDat->SignalLen-1); i++)
               {
                  SD[SigCount].data[i] = '0';
               }
               SD[SigCount].data[DeviceDat->SignalLen] = '\0';
             }
             SigCount++;
          }
       }
    }
  } while (ch != EOF);

   if (SigCount == 0) 
   {
      fprintf(stderr, "No signals for device!");
      return 1;
   }

   if (ValidityCount!=6) 
   {
      fprintf(stderr, "Not enough parameter data for device!");
      return 1;
   }

   fclose(data);
   return 0;
}

/*   THIS WORKS ON A PENTIUM ONLY 

int PlayIR(char* s, int n)         // ASM - Play signal back
{

__asm {
  mov esi, s   ; Get first argument
  mov ecx, n  ; Get second argument

// Identify printer port
	push		es				; Save ES and SI
	push		esi

	mov			ax, 40h
	mov			es, ax
	mov			esi, 0           ; Printer port -> SI (lpt1 = 0)
	shl			esi, 1
	mov			dx, es:[esi+8]   ; Port address -> DX
	inc			dx				; Port status reg is 1 byte higher

	pop			esi				; Pull ES and ESI back
	pop			es
	mov			ebx, 0           ; Set counter to 0

  //	this is the play_sequence procedure

  cli                       // Disable interrupts

// Wait loop until BUSY is low, ie. can then take next input
L2:	in			al, dx                // Read value into AL
  	mov			ah, al                // Make backup in AH
	  and			al, 10000000b					// Mask the BUSY bit...
	  cmp			al, 10000000b					// ... and check if set
	  je			L2

    // TRANSLATE THIS SO THEREIS NOERROR
    mov			al, [esi][ebx]					; Get next value in signal array
    

  	and     al, 00000010b         // Signal bit is bit 2
  	cmp			al, 00000000b					// Is it a "1" or "0"
  	je			P2										//

// P1:	
    mov			al, 00000010b	 // Output 0 at printer port
  	jmp			P3             // .. bit 2 flashes the LED

P2:	mov			al, 00000011b	 // Output 1 at printer port
	  jmp			P3             // .. bit 2 flashes the LED

P3:	mov     ah, 0                 // Function 0 = print char
    dec			dx                    // Set dx to printer port
 	  out     dx, al                // Output dx to port
	  inc     dx                    // Set dx back to status reg
	  inc			ebx										// Incriment array pointer
S2:	// Loop until trigger is set to 0 again (BUSY low)
  	in			al, dx
  	mov			ah, al
  	and			al, 10000000b
  	cmp			al, 10000000b
  	jne			S2

//P4:	// Main loop - count until the signal array is full
  	cmp			ebx, ecx
	  jle			L2

	// End of play loop, set the data line to 0
	mov			ah, 0                  // Function 0 = print char
	mov			al, 0                  // Set char to 0
	dec			dx
	out     dx, al                 // Print 0

// exit:	
   sti														// Allow interrupts again
  }

  return 1;

}


*/
