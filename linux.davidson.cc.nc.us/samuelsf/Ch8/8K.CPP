/*      Forrest Samuels

        CSC 134

        8k.cpp

        4.20.99

        This program will find the exit from a grid.
*/          

#include </student/public/grid>

bool NotInExit(grid g)
{
if( ((g.nRows() - 1) != g.row() ) && 
    ((g.nColumns() - 1) != g.column()) &&
     (g.row() != 0)  &&
     (g.column() != 0) )
return true;
}

void findExit(grid & g)
{

while(g.frontIsClear())  
	g.move(1);	

	if(NotInExit(g) == true)
	{	
		g.turnLeft();   
	
	do {
	  	while(g.frontIsClear()) 
	  	{
		  	g.move(1);
				
			if(g.rightIsClear()) 
			{
	 	  	  g.turnLeft();
		  	  g.turnLeft();
		  	  g.turnLeft();
		  	  g.move(1);
			}
		}
		if(NotInExit(g) == true)
		  g.turnLeft();			
	   }  
	while (NotInExit(g) == true);
	}	
}


void main()
{
	grid tarpit(10,16);
	
	tarpit.display();
	findExit(tarpit);
	tarpit.display();
}

