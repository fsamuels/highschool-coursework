
float nc_tax(float retail_price)
{
	const float tax = 0.06;         
	return retail_price * tax;
};
void bills(float change)
{
	int cash;
	cash = floor(change);
	cout<<"Number of hundreds: " << cash/100 << endl;
	cout<<"Number of fifties:  " << (cash%100)/50 << endl;
	cout<<"Number of twenties: " << ((cash%100)%50)/20 << endl;
	cout<<"Number of tens:     " << (((cash%100)%50)%20)/10 << endl;
	cout<<"Number of fives:    " << ((((cash%100)%50)%20)%10)/5 <<
endl;
	cout<<"Number of ones:     " << ((((cash%100)%50)%20)%10)%5 <<
endl;
};
void coin(float change)
{
	float rem;
	int coins;
	rem = change - floor(change);
//	cout << rem << endl;
	coins = rem*100;
	cout <<"Number of quarters: " << coins/25 << endl;
	cout <<"Number of dimes:    " << (coins%25)/10 << endl;
	cout <<"Number of nickles:  " << ((coins%25)%10)/5 << endl;
	cout <<"Number of pennies:  " << (((coins%25)%10)%5) << endl;
};
