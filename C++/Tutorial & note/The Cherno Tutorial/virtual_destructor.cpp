#include <iostream>
// When we derived a sub class, we must declared the destructor of our base class "a virtual destructor"
// without a "virtual" keyword declare, memory leak make take place (example below)

class Base
{
public:
	Base() { std::cout << "Base Constructor\n"; }
	virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base
{
public:
	int *m_Array;
	Derived()
	{
		m_Array = new int[5];
		std::cout << "Derived Constructor\n";
	}
	~Derived()
	{
		delete[] m_Array; // call it, or memery leak
		std::cout << "Derived Destructor\n";
	}
};

int main()
{
	Base *base = new Base();
	delete base;
	std::cout << "------------\n";
	Derived *derived = new Derived();
	delete derived;
	std::cout << "------------\n";
	Base *poly = new Derived();
	delete poly; // without virtual destructor, memory will leak here
	// without virtual declared, derived destructor WON'T be call here

	std::cin.get();
}
