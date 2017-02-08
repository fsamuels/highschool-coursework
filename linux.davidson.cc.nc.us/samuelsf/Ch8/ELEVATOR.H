//	Forrest Samuels
//	program 8h
//	April 12, 1999

//	elevator.h

class elevator {
public:

	elevator(int StartingFloor);
	// initalize elevator function at a floor
	
	void select(int NewFloor);
	//moves to NewFloor

private:

	int sfloor, nfloor;
};
