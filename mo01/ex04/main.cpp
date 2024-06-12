#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	// Error control
	if (argc != 4 || !*argv[2]) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	// Opening file stream
	std::string	fileName = argv[1];
	std::ifstream	ifs(fileName.c_str());
	if (!ifs.is_open()) {
		std::cerr << "Error opening file" << std::endl;
		return 1;
	}
	// Reading file stream
	std::string	text;
	std::string	line;
	while (getline(ifs, line))
	{
		text += line;
		text += "\n";
	}
	ifs.close();
	// Replacing strings
	std::string	before = argv[2];
	std::string	after = argv[3];
	size_t	ret = 0;
	do {
		ret = text.find(argv[2], ret);
		if (ret == std::string::npos)
			break;
		text.erase(ret, before.length());
		text.insert(ret, after);
	} while (1);
	// Writing to output file stream
	std::string	newFileName = fileName;
	newFileName += ".replace";
	std::ofstream	ofs(newFileName.c_str());
	ofs << text << std::endl;
	ofs.close();
}
