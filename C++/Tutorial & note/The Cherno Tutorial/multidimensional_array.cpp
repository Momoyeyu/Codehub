#include <iostream>

int main()
{
	// create a 2d array
	int **a2d = new int *[5];
	for (int i = 0; i < 5; i++)
	{
		a2d[i] = new int[5];
	}

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			a2d[x][y] = 2; // slower, because a2d[i] disperse in ram
		}
	}

	// u can do some "delete" here, but I will omit that since it is a sandbox program

	// create a 1d array
	int *array = new int[5 * 5];

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			array[x + y * 5] = 2; // faster, because all data in one line
		}
	}

	std::cin.get();
}
