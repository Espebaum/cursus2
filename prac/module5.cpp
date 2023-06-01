#include <iostream>
#include <string>
#include <cctype>

#define RESET		"\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

using namespace std;

class nofailplease
{
	private:
		string str;
	public:
		nofailplease()
		{
			cout << "fail 받더라도 기본 생성자는 존재해야만 한다\n";
		};
		nofailplease(string str) : str(str)
		{
			cout << BOLDBLUE << "fail 받더라도 생성자 오버로딩은 계속되어야만 한다 \n";
		};
};

void	PlusOneStack(string str)
{
	if (str == "fail")
			throw nofailplease(str);
	// 함수 안에 throw 문이 있는 경우 main이 아니라 함수 내에서 throw를 한 것이다
	// 이 경우,  함수의 스택 상에 try 블록이 존재하지 않는 경우에는
	// 오류가 발생한다. 현재 지역 안에 try가 없다면, 데이터를 빼들고 호출한 함수에서
	// try 블록을 찾게 되고, try 문이 존재한다면 그 곳에서 try 한 것과 같이 정상 처리된다.
}

void	FunctionCheckStack(string str)
{
	try 
	{
		PlusOneStack(str);
	}
	catch (nofailplease e)
	{
		cout << "예외를 또다시 throw할 수 있다는 사실에 대해 알고 계셨나요??\n";
		throw;
	}
}

int main()
{
	string str;

	try
	{
		cout << BOLDRED << "fail 주지 마세요.\n";
		cin >> str;
		FunctionCheckStack(str);
		cout << BOLDGREEN << "감사합니다\n";
	}

	catch (nofailplease e)
	{
		cout << BOLDMAGENTA << "저에게 3일은 영겁의 시간과 같습니다...\n";
	}

	catch (...)
	{
		cout << "DEFAULT EXCEPTION" << endl;
	}

	cout << BOLDCYAN << "프로그램을 종료합니다." << RESET << endl;

	return 0;
}
