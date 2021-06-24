#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		std::cout << "Usage : /path/to/exec fname s1 s2" << std::endl;
		return 1;
	}
	std::string		fname(argv[1]);
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::ifstream	ifs;
	std::ofstream	ofs;
	
	ifs.open(fname);
	if (!ifs.is_open())
	{
		std::cerr << "Cannot open file " << fname << " for reading" << std::endl;
		return 1;
	}
	ofs.open(fname + ".replace");
	if (!ofs.is_open())
	{
		std::cerr << "Cannot open file " << fname << " for writing" << std::endl;
		return 1;
	}

	size_t			i_prev;
	size_t			i;
	std::string		line;
	while (std::istream	&is = std::getline(ifs, line))
	{
		i_prev = 0;
		while (i_prev != line.length())
		{
			i = line.find(s1, i_prev);
			if (i == std::string::npos)
			{
				ofs << line.substr(i_prev);
				break;
			}
			else
			{
				ofs << line.substr(i_prev, i - i_prev) << s2;
				i_prev = i + s1.length();
			}
		}
		if (!is.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
