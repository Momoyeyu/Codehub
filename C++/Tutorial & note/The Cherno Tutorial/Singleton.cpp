#include <iostream>
#include <ctime>
#include <cstdlib>

// Singleton mode 单例模式

class Random
{
public:
	Random(const Random &) = delete; // don't allow constructing new instance

	// return the Singleton（单例）// this Get() function is the key of Singleton
	static Random &Get()
	{
		static Random instance;
		return instance;
	}

	// We can call Random::Int() instead of calling Random::Get().Int()
	static int Int() { return Get().ImpInt(); }

private:
	Random() {} // hide the default constructor

	int ImpInt()
	{
		std::srand((unsigned int)std::time(nullptr));
		int random_variable = std::rand();
		return random_variable;
	}
};

int main()
{
	std::cout << "Random number on [0, " << RAND_MAX << "]: " << Random::Int() << std::endl;

	std::cin.get();
}
