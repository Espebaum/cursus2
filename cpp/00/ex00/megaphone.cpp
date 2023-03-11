#include <iostream>
#include <string>

char	char_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (int j = 0; j < static_cast<int>(str.length()); j++)
			{
				std::cout << char_upper(str[j]);
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
