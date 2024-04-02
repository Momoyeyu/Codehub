#include <iostream>
#include <string>

class Player
{
private:
	std::string m_Name;
	static int Count;

public:
	Player()				// constructor
		: m_Name("Unknown") // the quick way to initialize instance variable (syntax sugar)
	{
		Count++;
		std::cout << "Player created!" << std::endl;
	}
	Player(const std::string &name) // another constructor
		: m_Name(name)
	{
		Count++;
		std::cout << "Player created!" << std::endl;
	}
	~Player() // destructor
	{
		Count--;
		std::cout << "Player Deleted!" << std::endl;
	}

	std::string GetName() { return m_Name; }

	static int GetCount() { return Count; }
};

int Player::Count(0); // Declare it by "int Player::Count(0)" only once, or compiler will throw a link error!

int main(void)
{
	{
		std::cout << "We have " << Player::GetCount() << "!" << std::endl; // 0

		Player p1("Cherno");   // calling constructor
		Player p2("Momoyeyu"); // calling constructor

		std::cout << "We have " << p1.GetCount() << "!" << std::endl; // 2

		std::cout << p1.GetName() << std::endl;
		std::cout << p2.GetName() << std::endl;
	}
	std::cout << "We have " << Player::GetCount() << "!" << std::endl; // 0
	std::cin.get();
}
