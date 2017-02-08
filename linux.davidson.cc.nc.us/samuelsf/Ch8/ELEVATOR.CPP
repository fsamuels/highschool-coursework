//	Forrest Samuels

//	elevator.cpp

#include <iostream>
using namespace std;

int floor;

elevator::elevator(int StartingFloor)
{
	sfloor = StartingFloor;
	cout << "start on floor " << sfloor << endl;
}

void elevator::select(int NewFloor)
{
	nfloor = NewFloor;
	
	if (sfloor == nfloor)
		cout << "open at " << nfloor << endl;
	if (sfloor < nfloor)
	{
		floor = sfloor;
	while(floor < nfloor)		
		{
		floor++;
		cout << "going up to " << floor << endl;
		}
		cout << "open at " << nfloor << endl;
		sfloor = floor;  //sets start as current floor
	}
	
	if (sfloor > nfloor)
	{
		floor = sfloor;	
	while(floor > nfloor)
		{
		floor = floor - 1;
		cout << "going down to " << floor << endl;
		}
	cout << "open at " << floor << endl;
	sfloor = floor;
	}
}

