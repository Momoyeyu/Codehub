#include <iostream>
#include <array> // std::array

// we use template so that we don't need to write a print for all kind of type and size
template <class T, size_t I>
void printArray(std::array<T, I>);

int main()
{
    // the size of std::array is bound with it's type when created
    std::array<int, 3> intArray{1, 2, 3}; // which mean that the size can't be change at run
    // if you need to change the size while running, use <vector>
    std::array<double, 2> doubleArray{2.2, 3.3};

    std::cout << "Printing Int Array\n";
    printArray(intArray);

    std::cout << "Printing Double Array\n";
    printArray(doubleArray);

    std::cin.get();
}

template <class T, size_t I>
void printArray(std::array<T, I> array)
{
    std::cout << "The size of this array is " << array.size() << std::endl; // size() method return the size
    for (T i : array)
    {
        std::cout << i << '\n';
    }
}
