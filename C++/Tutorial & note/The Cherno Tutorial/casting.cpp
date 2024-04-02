#include <iostream>

class Base
{
public:
	Base() {}		   // constructor
	virtual ~Base() {} // destructor
};

class Derived : public Base // inheritance（继承）
{
public:
	Derived() {}  // constructor
	~Derived() {} // destructor
};

class AnotherDerived : public Base
{
public:
	AnotherDerived() {}
	~AnotherDerived() {}
};

int main()
{
	double value = 5.25;
	double a = (int)value + 5.3; // C style casting
	std::cout << a << std::endl;

	double s = static_cast<int>(value) + 5.3; // C++ style casting
	// Question: what is the difference?
	// Answer:

	// static_cast:
	//		For basic casting, including unexplicit and explicit
	//		e.g: int x = 10; double y = static_cast<double>(x);
	//
	// reinterpret_cast:
	//		Cast without any boundary, including unsafe operation. Better only use in underlying code
	//		e.g: int* p = reinterpret_cast<int*>(0x1234);
	//
	// const_cast:
	//		To invalidate const keyword
	//		e.g: const int x = 10; int* p = const_cast<int*>(&x);
	//		WARNING: modify const value though the code above will lead to "undefine behaviour"
	//
	// dynamic_cast:
	//		Cast if only the target type is the type of the var or it's parent class or it's child class
	// 		usage: return nullptr if it isn't "castable"
	//		e.g: Derived* d = dynamic_cast<Derived*>(base_ptr);

	std::cout << "testing dynamic_cast:\n";
	Derived *derived = new Derived();

	Base *base;
	base = derived; // "base class ptr" can take "derived class ptr" WITHOUT casting

	// var *base "is-a Base" and "is-a Derived", but it "is-not-an AnotherDerived"
	AnotherDerived *ac = dynamic_cast<AnotherDerived *>(base);
	if (ac == nullptr) // equal to if (!ac)
		std::cout << "we can't dynamic_cast brother(sister) class to another\n";
	else
		std::cout << "we can dynamic_cast brother(sister) class to another\n";

	Base *bc = dynamic_cast<Base *>(derived);
	if (bc == nullptr) // equal to if (!ac)
		std::cout << "we can't dynamic_cast child class to parent class\n";
	else
		std::cout << "we can dynamic_cast child class to parent class\n";

	Derived *cc = dynamic_cast<Derived *>(base);
	if (cc == nullptr) // equal to if (!ac)
		std::cout << "we can't dynamic_cast parent class to child class\n";
	else
		std::cout << "we can dynamic_cast parent class to child class\n";

	/* output:
	 * 10.3
	 * we can't dynamic_cast brother(sister) class to another
	 * we can dynamic_cast child class to parent class
	 * we can dynamic_cast parent class to child class
	 *
	 */

	std::cin.get(); // get a single char, used as system("pause") here
}
