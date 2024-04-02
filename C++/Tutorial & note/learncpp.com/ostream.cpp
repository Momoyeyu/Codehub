/* Document:
* 
* For detail, please check out https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
* 
* There are two ways to change the formatting options: flags, and manipulators.
* You can think of flags as boolean variables that can be turned on and off.
* Manipulators are objects placed in a stream that affect the way things are input and output.
* 
* To switch a flag on, use the setf() function, with the appropriate flag as a parameter.
* using setf() to turn on some flags
* using unsetf() to turn off some flags
* 
* Using setf() and unsetf() tends to be awkward, so C++ provides a second way to change the formatting options: manipulators.
* The nice thing about manipulators is that they are smart enough to turn on and off the appropriate flags.
* 
* In general, using manipulators is much easier than setting and unsetting flags.
* Many options are available via both flags and manipulators (such as changing the base),
* however, other options are only available via flags or via manipulators, so it’s important to know how to use both.
*/
#include <iostream>
#include <iomanip>

int main()
{
	// setf(): turn on the flag
	// unsetf(): turn off the flag
	std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
	std::cout << 27 << '\n';

	std::cout.setf(std::ios::showpos | std::ios::uppercase); // turn on the std::ios::showpos and std::ios::uppercase flag
	std::cout << 1234567.89f << '\n';

	std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
	std::cout << 27 << '\n';
	std::cout.unsetf(std::ios::showpos); // turn off the std::ios::showpos flag
	std::cout << 28 << '\n';

	std::cout.setf(std::ios::hex); // try to turn on hex output
	std::cout << 27 << '\n';
	/*
	* It didn’t work! The reason why is because setf() only turns flags on:
	*	It isn’t smart enough to turn mutually exclusive flags off!
	* Consequently, when we turned std::hex on, std::ios::dec was still on, and std::ios::dec apparently takes precedence.
	* There are two ways to get around this problem: 
	*/

	// first way: turn off std::ios::dec so that only std::hex is set:
	std::cout.unsetf(std::ios::dec); // turn off decimal output
	std::cout.setf(std::ios::hex); // turn on hexadecimal output
	std::cout << 27 << '\n';

	// second way: turn on std::ios::hex as the only std::ios::basefield flag
	std::cout.setf(std::ios::hex, std::ios::basefield);// the second parameter is the formatting group it belongs to.
	std::cout << 27 << '\n';

	/*
	* Using setf() and unsetf() tends to be awkward, so C++ provides a second way to change the formatting options: manipulators. 
	* The nice thing about manipulators is that they are smart enough to turn on and off the appropriate flags.
	*/
	std::cout << std::hex << 27 << '\n'; // print 27 in hex // the advance is that it turn off std::dec for us autometically!
	std::cout << 28 << '\n'; // we're still in hex
	std::cout << std::dec << 29 << '\n'; // back to decimal


	std::cout << true << ' ' << false << '\n';
	std::cout.setf(std::ios::boolalpha); 
	std::cout << true << ' ' << false << '\n';
	std::cout << std::noboolalpha << true << ' ' << false << '\n'; // Booleans print 0 or 1 (default)
	std::cout << std::boolalpha << true << ' ' << false << '\n'; // Booleans print “true” or “false”


	std::cout << 5 << '\n';
	std::cout.setf(std::ios::showpos);
	std::cout << 5 << '\n';
	std::cout << std::noshowpos << 5 << '\n'; // Doesn’t prefix positive numbers with a +
	std::cout << std::showpos << 5 << '\n'; // Prefixes positive numbers with a +


	std::cout << 12345678.9 << '\n';
	std::cout.setf(std::ios::uppercase);
	std::cout << 12345678.9 << '\n';
	std::cout << std::nouppercase << 12345678.9 << '\n'; // Uses lower case letters(1.23457e+007)
	std::cout << std::uppercase << 12345678.9 << '\n'; // Uses upper case letters(1.23457E+007)


	/*
		Group					Flag				Meaning
		std::ios::basefield		std::ios::dec		Prints values in decimal (default)
		std::ios::basefield		std::ios::hex		Prints values in hexadecimal
		std::ios::basefield		std::ios::oct		Prints values in octal
		std::ios::basefield		(none)				Prints values according to leading characters of value

		Manipulator				Meanings
		std::dec				Prints values in decimal
		std::hex				Prints values in hexadecimal
		std::oct				Prints values in octal
	*/
	std::cout << 27 << '\n';
	std::cout.setf(std::ios::dec, std::ios::basefield);
	std::cout << 27 << '\n';
	std::cout.setf(std::ios::oct, std::ios::basefield);
	std::cout << 27 << '\n';
	std::cout.setf(std::ios::hex, std::ios::basefield);
	std::cout << 27 << '\n';
	std::cout << std::dec << 27 << '\n';
	std::cout << std::oct << 27 << '\n';
	std::cout << std::hex << 27 << '\n';


	/*
		Group					Flag					Meaning
		std::ios::floatfield	std::ios::fixed			Uses decimal notation for floating-point numbers
		std::ios::floatfield	std::ios::scientific	Uses scientific notation for floating-point numbers
		std::ios::floatfield	(none)					Uses fixed for numbers with few digits, scientific otherwise
		std::ios::floatfield	std::ios::showpoint		Always show a decimal point and trailing 0’s for floating-point values

		Manipulator				Meaning
		std::fixed				Use decimal notation for values
		std::scientific			Use scientific notation for values
		std::showpoint			Show a decimal point and trailing 0’s for floating-point values
		std::noshowpoint		Don’t show a decimal point and trailing 0’s for floating-point values
		std::setprecision(int)	Sets the precision of floating-point numbers (defined in the iomanip header)
	*/
	std::cout << std::fixed << '\n';
	std::cout << std::setprecision(3) << 123.456 << '\n';
	std::cout << std::setprecision(4) << 123.456 << '\n';
	std::cout << std::setprecision(5) << 123.456 << '\n';
	std::cout << std::setprecision(6) << 123.456 << '\n';
	std::cout << std::setprecision(7) << 123.456 << '\n';

	std::cout << std::scientific << '\n'; // 科学计数法
	std::cout << std::setprecision(3) << 123.456 << '\n';
	std::cout << std::setprecision(4) << 123.456 << '\n';
	std::cout << std::setprecision(5) << 123.456 << '\n';
	std::cout << std::setprecision(6) << 123.456 << '\n';
	std::cout << std::setprecision(7) << 123.456 << '\n';


	std::cout << -12345 << '\n'; // print default value with no field width
	std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
	std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
	std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
	std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified


	std::cout.fill('*');
	std::cout << -12345 << '\n'; // print default value with no field width
	std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
	std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
	std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
	std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified

	
	return 0;
}