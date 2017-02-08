/* Forrest Samuels		CSC 134

	2.24.99

	This program will move a mover on a grid 3 places.

*/

#include </student/public/grid>
#include <iostream>
using namespace std;

grid moveThree(grid g)
{

	g.move(3);
	return g;	

}

int main()
{
	grid tarpit(4, 10, 1, 1, east);
	tarpit = moveThree(tarpit);
	tarpit.display();
	return 0;
}
