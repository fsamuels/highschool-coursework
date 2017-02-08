//#include </student/csc134HA/samuelsf/Ch6/counter.h>
//using namespace std;

counter::counter(int startingValue, int maxValue)
{
	my_count = startingValue;
	my_maxValue = maxValue;
}

void counter::click()
{
	if(my_count == my_maxValue)
	{
		my_count = 0;
	}

	else
	{
		my_count = my_count + 1;
	}
}

void counter::reset()
{
	my_count = 0;
}

int counter::count() const
{
	return my_count;
}
