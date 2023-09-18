#pragma once

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock() {}
		Warlock(const Warlock& ref) { *this = ref; }
		Warlock& operator=(const Warlock& ref) { static_cast<void>(ref); return *this; }
	public:
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& ref);
		void introduce() const;
		Warlock(const std::string& name, const std::string& title);
		~Warlock();
};
