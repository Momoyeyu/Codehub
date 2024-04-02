#include <iostream>
#include <string>

// note that the template function don't exist until it is call
template <typename T> // "T" is customized name
void Print(T value)
{
	std::cout << value << std::endl;
}

template <typename T, int N> //
class Array
{
private:
	T m_Array[N];

public:
	int GetSize() const { return N; }
};

int main()
{

	std::cout << "Example of function template:" << std::endl;
	// the type of T will be the that in parenthesis when compile
	Print(5);
	Print("Hello");
	Print(5.5f);

	// or we can explicitly write the typename in <> such as <int>
	Print<int>(6);
	Print<std::string>("Hello");

	// compilation will fail if type didn't match

	std::cout << "Example of class template:" << std::endl;
	Array<int, 5> array;
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}
