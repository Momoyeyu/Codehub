#include <iostream>

template <typename T, size_t S>
class Array
{
public:
	constexpr unsigned int Size() const { return S; }

	T& operator[](size_t index) { return m_Data[index]; }
	const T& operator[](size_t index) const { return m_Data[index]; }

	T* Data() { return &m_Data; }
	const T* Data() const { return &m_Data; }
private:
	T m_Data[S];
};

int main()
{

	Array<int, 5> data;
	memset(&data[0], 0, data.Size() * sizeof(int));
	std::cout << "Size equal to " << data.Size() << std::endl;

	for (int i = 0; i < data.Size(); i++)
	{
		std::cout <<"data " << i << " equal to " << data[i] << std::endl;
	}  

	std::cin.get();
}