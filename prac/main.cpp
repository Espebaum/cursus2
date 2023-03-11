#include <iostream>

class Date 
{
	int year;
	int month;  // 1 부터 12 까지.
	int day;    // 1 부터 31 까지.

	public:
	void SetDate(int _year, int _month, int _day)
	{
		if ((_month < 1 || _month > 12) || (_day < 1 || _day > 31))
		{
			std::cout<<"잘못된 월일 설정입니다.";
		}
		if (_month == 2 && _day > 29)
			std::cout<<"2월은 28일까지 있습니다.";
		year = _year;
		month = _month;
		day = _day;

	}
	void AddDay(int inc)
	{

	}
	void AddMonth(int inc);
	void AddYear(int inc);

	void ShowDate();
};

int	main()
{
	Date	date;

	date.SetDate(2023, 9, 18);

	return 0;
}
