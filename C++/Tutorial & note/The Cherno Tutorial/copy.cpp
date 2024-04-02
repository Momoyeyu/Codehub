#include <iostream>
#include <string>

class String
{
private:
	char *m_Buffer;
	unsigned int m_Size;

public:
	String(const char *tmp_string) // build our String from a const char*
	{
		m_Size = strlen(tmp_string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, tmp_string, m_Size); // args: (*dest, *src, size)
		m_Buffer[m_Size] = 0;				  // the string_end signal
	}

	String(const String &other) // construct another from our String class. use reference& here to avoid copy at function calling
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // copy 0 at the same time
	}

	~String()
	{
		delete[] m_Buffer; // free our buffer manually since it is created by "new"
	}

	// use "friend" keyword to allow outer function access private variable
	friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

// let our String class can be printed by "std::cout", which is an ostream
std::ostream &operator<<(std::ostream &stream, const String &m_string)
{
	stream << m_string.m_Buffer;
	return stream;
}

int main()
{
	String m_string = "Cherno";
	std::cout << m_string << std::endl;
	std::cin.get();
}
