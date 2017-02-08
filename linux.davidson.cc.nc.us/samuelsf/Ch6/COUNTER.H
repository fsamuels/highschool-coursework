class counter {
public:
	counter(int startingValue, int maxValue);
	// post: Initalize counter to startingValue
	//	 and set the max count

	void click();
	// post: If count is at max
	//	 set counter to 0, otherwise add 1 to count

	void reset();
	// post: resets counter to 0

	int count() const;
	// post: returns current count

private:
	int my_count;
	int my_maxValue;
};
