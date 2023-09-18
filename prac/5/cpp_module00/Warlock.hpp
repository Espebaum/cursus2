#pragma once

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock() {};
		Warlock(const Warlock& ref) { *this = ref; }
		Warlock& operator=(const Warlock& ref) { static_cast<void>(ref); return *this; }
	public:
		~Warlock();
		Warlock(const std::string& _name, const std::string& _title);
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& ref);
		void introduce() const;
};
