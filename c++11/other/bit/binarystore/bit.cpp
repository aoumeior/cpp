constexpr unsigned int N = 1000000;
constexpr unsigned int word_length = sizeof(int) * 8;

/*
 *@bits is test array
 *@i	is number
 */
void setbit(unsigned int *bits, unsigned int i)
{

	// i/word_length is used to look for correct bit array
	// 1 << (i%word_length) is used to set correct mark site
	bits[i / word_length] |= 1 << (i % word_length);
}

int testbit(unsigned int *bits, unsigned int i)
{

	return bits[i / word_length] & (i << (i % word_length));
}

// initialize array
unsigned int bits[N / word_length + 1] = {0};

/*
 *@xs This array is used to find the minimum value of the available
 *@n  find the maximum limit in array
 */
int minFree(int *xs, int n)
{

	int len = N / word_length + 1;

	for (int i{0}; i < len; ++i)
	{
		if (xs[i] < n)
			setbit(bits, xs[i]);
	}

	for (int i{0}; i < len; ++i)
	{

		if (!testbit(bits, i))
			return i;
	}
	return -1;
}