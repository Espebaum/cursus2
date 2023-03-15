#include "cperson.hpp"
#include <iostream>
#include <string>
using namespace std;

//c++의 클래스를 c 구조체로 구현해보는 부분
struct c_Person
{
	string	name;
	int		age;

	int(*getAge)(c_Person *);
	void(*setAge)(c_Person *, int);
	string(*getName)(c_Person *);
	void(*setName)(c_Person *, string);
};

int	getAge(c_Person *person)
{
	return (person->age);
}

void	setAge(c_Person *person, int given_age)
{
	person->age = given_age;
}

string	getName(c_Person *person)
{
	return (person->name);
}

void	setName(c_Person *person, string given_name)
{
	person->name = given_name;
}

int main()
{
	//구조체 선언
	c_Person	gyopark;
	gyopark.getAge = getAge;
	gyopark.getName = getName;
	gyopark.setAge = setAge;
	gyopark.setName = setName;
	// 함수 포인터에 연결

	gyopark.setName(&gyopark, "gyo");
	std::cout << gyopark.name << std::endl;
}
