#include <iostream>
#include <chrono> // we use it to make our timer
#include <thread>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end; // type of time
	std::chrono::duration<float> duration;						   // float number in seconds 以秒为单位的浮点数

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start; // end is greater than start since the time is always growing larger

		// an interesting thing here is that using double here seem to cost more time than float
		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took " << ms << "ms" << std::endl;
	}
};

void Function_1()
{
	Timer timer;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "calling endl;" << std::endl; // we use std::endl here
	}
}

void Function_2()
{
	Timer timer;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "calling \\n"; // we use \n here
	}
}

int main()
{
	Function_1(); // std::endl method (slower)

	Function_2(); // \n method (faster)

	std::cin.get();
}
