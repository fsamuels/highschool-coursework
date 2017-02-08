/* 	Forrest Samuels

	SimpleTron

	csc 134

	April 26, 1999

	This is the final project for the whole class. It is known as the
SipleTron. It is some crazy computer simulator deal that has a stupid
language that does very little. Hopefully it will work when I turn it in.

GRADE: 100
*/

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include </afs/unity.ncsu.edu/users/d/dfsamuel/linux.davidson.cc.nc.us/STUDENT/PUBLIC/VECTOR>
#include </afs/unity.ncsu.edu/users/d/dfsamuel/linux.davidson.cc.nc.us/STUDENT/PUBLIC/compfun>

	int counter = 0;
        int accumulator = 0;
        int operationCode = 0;
        int operand = 0;
        int instructionRegister = 0;
        int data = 0;
        int tempdata = 0;
        int numinputs = 0;
	int exitprogram = 0;
        string filename;
	string reason;

	const int READ       = 10;
        const int WRITE      = 11;
        const int LOAD       = 20;
        const int STORE      = 21;
        const int ADD        = 30;
        const int SUBTRACT   = 31;
        const int DIVIDE     = 32;
        const int MULTIPLY   = 33;
        const int BRANCH     = 40;
        const int BRANCHNEG  = 41;
        const int BRANCHZERO = 42;
        const int HALT       = 43;

        vector <int> memory(100, 0); //defines memory[100] with 0 values

void CoreDump(string reason)
{
clearScreen();
cout <<  reason << " (core dumped)" << endl << endl;
cout << "REGISTERS:" << endl;
cout << "accumulator          " << accumulator << endl;
cout << "counter              " << counter << endl;
cout << "instructionRegister  " << instructionRegister << endl;
cout << "operationCode        " << operationCode << endl;
cout << "operand              " << operand << endl;
cout << endl;
cout << "MEMORY:" << endl;

cout << "       0     1     2     3     4     5     6     7     8     9";
cout << endl;
cout << " 0";
for(int z = 0; z <=9; z++)
{
	if (memory[z] == 0)
		cout << " +0000";
	else
		cout << " +" << memory[z];
}
cout << endl << "10";
for(int z = 9; z <=18; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}                  
cout << endl << "20";
for(int z = 19; z <=28; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}      
cout << endl << "30";
for(int z = 29; z <=38; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}         
cout << endl << "40";
for(int z = 39; z <=48; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}         
cout << endl << "50";
for(int z = 49; z <=58; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}         
cout << endl << "60";
for(int z = 59; z <=68; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}         
cout << endl << "70";
for(int z = 69; z <=78; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}         
cout << endl << "80";
for(int z = 79; z <=88; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}         
cout << endl << "90";
for(int z = 89; z <=98; z++)
{
        if (memory[z] == 0)
                cout << " +0000";
        else
                cout << " +" << memory[z];
}         
cout << endl;

}            

void main()
{
clearScreen();
cout << "***            Welcome to Simpletron            ***" << endl; 
cout << endl;
cout << "*** Please enter the filename of your data file ***" << endl;
cout << "*** when prompted. ***" << endl;
cout << endl;
cout << "*************************************************" << endl;
cout << endl;

///////////////////// GET INPUT FILE ///////////////
int x = 1;

do {
cout << "Please type in the filename that your code is in. Please remember 
to use the complete path if need be: ";
cin >> filename;
	
	ifstream inFile(filename.c_str());
	if (! inFile)
		cout << "Invalid Filename!!" << endl;
	else
		x = 0;

} while (x == 1);

///////////////////////////////////////////////
///////// PLACE EACH LINE INTO MEMORY /////////

	ifstream inFile(filename.c_str()); //for some reason I have to
					   //re-declare this function or
					   //it will complain about an
					   //undeclared function
while (inFile >> data)
{
	memory[counter] = data;
	 if (data > 9999 || data < -9999)
                {
                exitprogram = 1;
                reason = "*** Input out of range! ***";
                CoreDump(reason);
                }    
	counter++;
}
if (exitprogram == 1)
        cout << endl;
else{ 
///////////////////////////////////////////////
///////// OUTPUT THE INPUT FROM FILE///////////

numinputs = counter - 1; //will be used later for execution

for (int i = 0; i <= (counter - 1); i++)
{
	if (i >=0 && i <= 9)
		cout << "0";
	
	cout << i << " ? ";

	if (memory[i] == 0)
		cout << "000";

	cout << memory[i] << endl;
}
	cout << endl << "*** Program loading completed ***" << endl;
	cout << "*** Program execution begins  ***" << endl;

//////////////////////////////////////////////////////
///////////////// RUNS ACCTUAL PROGRAM ///////////////	
for (counter = 0; counter <= numinputs; counter++)
{
	instructionRegister = memory[counter];
	operationCode = instructionRegister / 100;
	operand = (instructionRegister - (operationCode * 100));


	switch(operationCode)
	{
case READ:
	cout << "input to location " << operand << "?";
	cin >> tempdata;
	memory[operand] = tempdata;
	break;

case WRITE:
	cout << memory[operand] << endl;
	break;

case LOAD:
	accumulator = memory[operand];
	if (accumulator > 9999 || accumulator < -9999)
		{
		counter = numinputs + 1;
		reason = "*** Accumulator out of range! ***";
		CoreDump(reason);
		}
	break;

case STORE:
	memory[operand] = accumulator;
	break;

case ADD:
	accumulator += memory[operand];
	if (accumulator > 9999 || accumulator < -9999)
                {
                counter = numinputs + 1;
		reason = "*** Accumulator out of range! ***";
                CoreDump(reason);
                } 
	break;

case SUBTRACT:
	accumulator -= memory[operand];
	if (accumulator > 9999 || accumulator < -9999)
                {
                counter = numinputs + 1;
		reason = "*** Accumulator out of range! ***";
                CoreDump(reason);
                } 
	break;

case DIVIDE:
	if (memory[operand] == 0)
		{
		reason = "*** Attempt to divide by zero! ***";
		CoreDump(reason);
		}
  	accumulator = accumulator / memory[operand];
	if (accumulator > 9999 || accumulator < -9999)
                {
                counter = numinputs + 1;
		reason = "*** Accumulator out of range! ***";
                CoreDump(reason);
                } 
	break;

case MULTIPLY:
	accumulator = accumulator * memory[operand];
	if (accumulator > 9999 || accumulator < -9999)
                {
                counter = numinputs + 1;
		reason = "*** Accumulator out of range! ***";
                CoreDump(reason);
                } 
	break;

case BRANCH:
	counter = operand - 1;
	break;

case BRANCHNEG:
	if (accumulator < 0)
		counter = operand - 1;
	break;

case BRANCHZERO:
	if (accumulator == 0)
		counter = operand - 1;
	break;

case HALT: 
	counter = numinputs + 1;
	break;
	}
}
}
}
