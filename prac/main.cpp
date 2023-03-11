#include <iostream>
#include <string>

int main() {
	std::string t;
  while (true) 
  {
    std::cin >> t;
    std::cout << "입력 :: " << t << std::endl;
	// if (std::cin.eof())
	// {
	//     std::cout << "ctrl D를 누르셨나요?"	<< std::endl;
	// }
	if (std::cin.fail() || std::cin.eof())
	{
		// if (std::cin.eof())
		// {
		//     std::cout << "Ctrl D를 입력하셨나요?" << std::endl;
		// }
		// else if (std::cin.fail())
		// {
		//     std::cout << "제대로~" << std::endl;
		//     std::cin.clear();
		//     std::cin.ignore();
		// }
		if (std::cin.fail() && std::cin.eof())
		{
			std::cout << "Ctrl D?" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\0');
		}
    }
    if (t == "w") break;
  }
}
