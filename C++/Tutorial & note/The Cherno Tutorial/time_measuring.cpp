#include <iostream>
#include <memory>
#include <chrono>
#include <array>

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
	// "std::chrono::time_point": a time point container
	// "std::chrono::high_resolution_clock": a clock whose ::now() method return is current time point

public:
	Timer()
	{
		std::cout << "[Timer] start timing\n";
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << "[Timer] use " << ms << " ms\n";
	}
};

int main()
{
	// example 1:
	int value = 0;
	{
		// If we run this code in Release mode, we can't get the right time because compiler have calulate the result of value for us. Because add operaion here is useless. Check it out in the assemble code of Release mode
		Timer timer;
		for (int i = 0; i < 1000000; i++)
			value += 2;
		std::cout << value << std::endl;
	}

	// example 2:
	struct Vector2
	{
		float x, y;
	};

	std::cout << "Make shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>(/*params here to call other constructor*/);
	}

	std::cout << "New shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
	}

	std::cout << "Make Unique\n";
	{
		std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
		Timer timer;
		for (int i = 0; i < uniquePtrs.size(); i++)
			uniquePtrs[i] = std::make_unique<Vector2>();
	}
	// In debug mode, we can't tell whether "Make Shared" or "New Shared" is faster.
	// That is because the debugger do lots of extra things.
	// In released mode, you will find that "Make Shared" is always faster than "New Shared"

	//__debugbreak(); // break point

	std::cout << "Press Enter to quit";
	std::cin.get();
	return 0;
}
