#include <iostream>
#include <string>

std::string	ridrspace(std::string& tmp)
{
    int len = tmp.length();

    while (tmp[len - 1] == ' ')
        len--;
    return (tmp.substr(0, len));
}

int main()
{	
    std::string info[5];
    std::string input[5] = {"First Name : ", "Last Name : ", 
	"Nickname : ", "Phone Number : ", "Darkest Secret : "};
	std::string	tmp;

    for (int i = 0; i < 5; i++)
    {
		info[i] = "";
		std::cout << input[i];
		while (info[i] == "")
		{
			std::getline(std::cin, tmp);
            if (std::cin.eof())
            {
                exit(0);
            }
            std::string new_tmp = ridrspace(tmp);
			info[i] = new_tmp;
		}
    }

    for (int i = 0; i < 5; i++)
        std::cout << info[i] << " ";
    std::cout << std::endl;
}