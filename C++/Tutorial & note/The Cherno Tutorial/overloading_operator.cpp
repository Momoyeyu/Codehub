#include <iostream>

struct Vector3
{
    float x, y, z;

    Vector3(float x, float y, float z) // constructor
        : x(x), y(y), z(z)             // syntax sugar
    {
    }

    Vector3(const Vector3 &other) : x(other.x), y(other.y), z(other.z)
    {
    }

    Vector3 operator+(const Vector3 &other) // override operator +
    {
        return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    Vector3 operator++() // override operator
    {
        x++;
        y++;
        z++;
        return *this;
    }

    Vector3 operator--()
    {
        x--;
        y--;
        z--;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &stream, const Vector3 vector) // override operator <<
{
    stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
    return stream;
}

class Array
{
private:
    int *data;
    int size;

public:
    Array(int size) : size(size)
    {
        data = new int[size];
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
};

class Counter
{
private:
    int count;

public:
    Counter(int count) : count(count) {}

    // Prefix increment operator
    Counter &operator++()
    {
        ++count;
        return *this;
    }

    // Postfix increment operator
    Counter operator++(int)
    {
        Counter temp = *this;
        ++count;
        return temp;
    }

    int getCount() const
    {
        return count;
    }
};

class Point
{
private:
    double x;
    double y;

public:
    Point(double x, double y) : x(x), y(y) {}

    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Point &point)
    {
        is >> point.x >> point.y;
        return is;
    }
};

int main()
{
    Vector3 vector1 = {2, 5, 8};
    Vector3 vector2 = {4, 6, 7};
    Vector3 vector3 = vector1 + vector2; // overload operator +

    std::cout << vector1 << std::endl; // overload operator <<

    std::cin.get();
}
