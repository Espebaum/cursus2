#include "Person.hpp"
#include <iostream>
#include <string>
using namespace std;

Person::~Person()
{
	cout<<"기본 소멸자, 소멸자는 객체가 소멸할 때 호출되며 반환값이 없습니다."<<endl;
}

Person::Person()
{
	cout<<"기본 생성자, 생성자는 실제로 생성된 객체의 참조값을 반환합니다."<<endl;
}

Person::Person(string name, int age) : name(name), age(age)
{
	cout<<"생성자 오버로딩"<<endl;
}

string	Person::Getname() const
{
	return (this->name);
}

int	Person::GetAge() const
{
	return (this->age);
}

void	Person::SetName(string name)
{
	this->name = name;
}

void	Person::SetAge(int age)
{
	this->age = age;
}

int main()
{
	Person	person1; //기본 생성자 호출
	Person	person2("gyopark", 25);
	Person	*person3 = new Person("hyeonseo", 25);
	// person.SetName("gyopark");
	// person.SetAge(25);
	cout<<person2.Getname()<<endl<<person2.GetAge()<<endl<<person3->Getname()<<endl<<person3->GetAge()<<endl;
	delete person3;
	// return (0);
}
