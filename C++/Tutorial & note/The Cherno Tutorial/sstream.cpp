#include <iostream>
#include <string>
#include <sstream>

class Array
{
private:
	int x, y;

public:
	Array(int x, int y) : x(x), y(y) {}

	~Array() {}

	void print()
	{
		std::cout << this->toString() << "\n";
	}

	std::string toString() const
	{
		std::stringstream ss;				// <sstream>
		ss << "[" << x << ", " << y << "]"; // like "StringBuilder" in Java
		return ss.str();					// str(): turn "std::stringstream" to "std::string"
	}

	friend std::ostream &operator<<(std::ostream &, const Array &);
};

int main()
{

	Array arr(1, 1); // calling constructor
	Array ar = {1, 2};

	arr.print();
	ar.print();

	std::cout << arr << ar;
}

std::ostream &operator<<(std::ostream &stream, const Array &arr)
{
	stream << arr.toString();
	return stream;
}
