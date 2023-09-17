#pragma once

#include <iostream>
#include <string>

class Warlock 
{
	private:
		std::string	name; // 체크
		std::string title;
		Warlock();
		Warlock(const Warlock& ref);
		Warlock& operator=(const Warlock& ref);
	
	public:
		~Warlock();
		Warlock(const std::string& _name, const std::string& _title); 
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& title);
		void introduce() const;	
};
