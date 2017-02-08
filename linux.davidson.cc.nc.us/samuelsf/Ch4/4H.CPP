/* Forrest Samuels		CSC 134
*
*  Feburary 11, 1999
*
*  This program will construct a 3 by 24 grid with the mover in row 1,
*  column 0.. and then make a pattern looing like in the book.
*/

#include "/student/public/grid"

void main()
{

//Input Section

	
//Process Section

	grid OneCrazyGrid(3, 24, 1, 0, east);

	OneCrazyGrid.move(1);
	OneCrazyGrid.putDown();
	
	OneCrazyGrid.move(2);
	OneCrazyGrid.putDown();	
	
	OneCrazyGrid.move(2);
        OneCrazyGrid.putDown();
	
	OneCrazyGrid.move(2); 
 	OneCrazyGrid.putDown();
        
	OneCrazyGrid.move(2);
        OneCrazyGrid.putDown(); 
 	
	OneCrazyGrid.move(2);
        OneCrazyGrid.putDown();
        
	OneCrazyGrid.move(2); 
 	OneCrazyGrid.putDown();
        
	OneCrazyGrid.move(2);
        OneCrazyGrid.putDown(); 
	
	OneCrazyGrid.move(2);
        OneCrazyGrid.putDown();

	OneCrazyGrid.move(2);
        OneCrazyGrid.putDown();

	OneCrazyGrid.move(2);
        OneCrazyGrid.putDown();

	OneCrazyGrid.move(2);
	
//Output Section

	OneCrazyGrid.display();

}
