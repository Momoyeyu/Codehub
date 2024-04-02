#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals; // for "1s" in line 24 "std::this_thread::sleep_for(1s);"

	std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;
	int count = 0;
	while (!s_Finished)
	{
		count++;
		if (count > 5)
		{
			count = 0;
			std::cout << "press enter to free the worker from work\n";
		}
		else
		{
			std::cout << "Working...\n";
		}
		std::this_thread::sleep_for(1s);
	}
	std::cout << "Stop working now.\n";
	std::this_thread::sleep_for(1s);

	std::cout << "Work done!\n";
}

int main()
{
	std::thread worker(DoWork); // create a thread name worker

	std::cin.get();
	s_Finished = true; // it is a file scope var

	worker.join(); // wait until the thread worker end
	std::cout << "Finished." << std::endl;

	std::cout << "main thread id=" << std::this_thread::get_id() << std::endl;

	std::cin.get();
}
