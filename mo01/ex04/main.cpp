#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::string	fileName = argv[1];
	std::ifstream	ifs(fileName);
	if (!ifs.is_open()) {
		std::cerr << "Error opening file" << std::endl;
		return 1;
	}

	std::string	before = argv[2];
	std::string	after = argv[3];

	std::string	text;
	std::string	line;
	while (getline(ifs, line))
	{
		text += line;
		text += "\n";
	}
	ifs.close();

	size_t	ret = 0;
	do {
		ret = text.find(argv[2], ret);
		if (ret == std::string::npos)
			break;
		text.erase(ret, before.length());
		text.insert(ret, after);
	} while (1);

	std::string	newFileName = fileName;
	newFileName += ".replace";
	std::ofstream	ofs(newFileName);
	ofs << text << std::endl;
	ofs.close();
	return 0;
}
