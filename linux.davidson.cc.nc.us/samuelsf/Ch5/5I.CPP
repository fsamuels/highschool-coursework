/* Forrest Samuels		CSC 134

	3.2.99

	This program will move a mover on a grid 3 places using the &
thing to allow values to change within the function.

*/

#include </student/public/grid>
#include <iostream>
using namespace std;

void moveThree(grid & g)
{

	g.move(3);

}

int main()
{
	grid tarpit(4, 10, 1, 1, east);
	moveThree(tarpit);
	tarpit.display();
	return 0;
}
