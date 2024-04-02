#pragma once
#include <iostream>
#include <string>

class String {
private:
	char* m_data;
	size_t m_length;

public:
	// deflaut constructor
	String()
		: m_data(nullptr), m_length(0)
	{}

	//constructor
	String(const char* str) {
		m_length = strlen(str);
		m_data = new char[m_length + 1];
		strcpy(m_data, str);
	}

	// destructor
	~String() {
		delete[] m_data;
	}

	// overload operator=
	String& operator=(const String& other) {
		if (this != &other) {
			delete[] m_data;
			m_length = other.m_length;
			m_data = new char[m_length + 1];
			strcpy(m_data, other.m_data);
		}
		return *this;
	}

	// overload operator+
	String operator+(const String& other) const {
		size_t newlength = m_length + other.m_length;
		char* newData = new char[newlength + 1];
		strcpy(newData, m_data);
		strcat(newData, other.m_data);
		String result(newData);
		delete[] newData;
		return result;
	}

	String operator+(const String& other) const {
		size_t newlength = m_length + other.m_length;
		char* newData = new char[newlength + 1];
		strcpy(newData, m_data);
		strcat(newData, other.m_data);
		String result(newData);
		delete[] newData;
		return result;
	}

	String operator+(const char* other) const {
		size_t newlength = m_length + strlen(other);
		char* newData = new char[newlength + 1];
		strcpy(newData, m_data);
		strcat(newData, other);
		String result(newData);
		delete[] newData;
		return result;
	}

	String& operator+=(const String& other) {
		m_length += other.m_length;
		char* new_data = new char[m_length + 1];
		strcpy(new_data, m_data);
		strcat(new_data, other.m_data);
		delete[] m_data;
		m_data = new_data;
		delete[] new_data;
		return *this;
	}

	// overloading operator[]
	char& operator[](size_t index) {
		if (index >= m_length) {
			// solving out-of-range problem
			throw std::out_of_range("Index out of range");
		}
		return m_data[index];
	}

	const char& operator[](size_t index) const {
		if (index >= m_length) {
			// solving out-of-range problem
			throw std::out_of_range("Index out of range");
		}
		return m_data[index];
	}

	String substr(size_t size) const {
		if (size >= m_length) {
			// return full string
			return *this;
		}

		char* newData = new char[size + 1];
		strncpy(newData, m_data, size);
		newData[size] = '\0';

		String result(newData);
		delete[] newData;

		return result;
	}

	operator const char* () const {
		return m_data;
	}

	operator std::string() const {
		std::string str = m_data;
		return str;
	}

	const char* c_str() const {
		return m_data;
	}
};