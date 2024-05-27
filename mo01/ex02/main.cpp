#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Memory address of the string variable:\t\t" << &string << std::endl;
	std::cout << "Memory address held by stringPTR:\t\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:\t\t" << &stringREF << std::endl;

	std::cout << "Value of the string variable:\t\t\t" << string << std::endl;
	std::cout << "Value pointed to by stringPTR:\t\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\t\t\t" << stringREF << std::endl;

	return 0;
}
