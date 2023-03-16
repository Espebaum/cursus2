#include <iostream>
#include <fstream>
#include <string>

#define RESET   "\033[0m"		/* Reset Color */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << BOLDWHITE << "Error! Invalid number of argument" << std::endl;
		return (1);
	}

	std::string	s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream ifs;
	std::ofstream ofs;
	
	if (static_cast<int>(std::strlen(argv[1])) == 0 || s1.length() == 0 || s2.length() == 0)
	{
		std::cerr << BOLDWHITE << "Error! String must have length more than 0" << std::endl;
		return (1);
	}
	
	ifs.open(argv[1]); // void open(const char* __s, ios_base::openmode __mode)
	
	if (ifs.fail())
	{
		std::cerr << BOLDWHITE << "Error! Failed to open file" << std::endl; 
		return (1);
	}

	std::string outfile = static_cast<std::string>(argv[1]).append(".replace");
	ofs.open(outfile);
	if (ofs.fail())
	{
		std::cerr << BOLDWHITE << "Error! Failed to open file" << std::endl; 
		return (1);
	}

	std::string line;
	while (1)
	{
		std::getline(ifs, line);			
		size_t pos = 0;
		while (1)
		{
			pos = line.find(s1, pos);
			if (pos == std::string::npos)
			{
				break;
			}
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		ofs << line;
		if (ifs.eof())
			break ;
		ofs << std::endl;
	}
	return (0);
}
