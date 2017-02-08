#include </student/public/cmath> //for sqrt()
#include <iostream> //for cout

// -- Constructors

quadraticEquation::quadraticEquation(double initA, double initB, double
initC)
{
	my_a = initA;
	my_b = initB;
	my_c = initC;

// my_d is equal to (b^2 - 4ac)
// it can be used to not have to calculate it everytime 
// also needed to determine if real or imaginary roots

	my_d = (my_b * my_b) - (4 * my_a * my_c); 
}

// -- accessors

double quadraticEquation::root1() const
{
	return (-my_b + sqrt(my_d)) / (2 * my_a);	
}		

double quadraticEquation::root2() const
{
	return (-my_b - sqrt(my_d)) / (2 * my_a);
}

bool quadraticEquation::hasRealRoots() const
{
	if (my_d >= 0.0)
	  return true;
	else
	  return false;
}

void quadraticEquation::display() const
{
	cout << my_a << "x^2 ";	

	if (my_b < 0)
		cout << "- " << (my_b * -1) << "x ";
	else
		cout << "+ " << my_b << "x ";

	if (my_c < 0)
		cout << "- " << (my_c * -1);
	else
		cout << "+ " << my_c << endl;

	cout << " ";	
}
