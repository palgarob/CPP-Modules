#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open()) {
		std::cerr << "Error opening file" << std::endl;
		return 1;
	}
	std::string	text;
	std::string	line;
	while (getline(ifs, line))
		text += line;
}
