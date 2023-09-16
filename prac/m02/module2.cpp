#include <iostream>

#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int		arg = 0;

typedef struct	prac
{
	int	a;
	int	*b; 
}	t_prac;

class c_prac
{
	private:
		int a;
		int *b;
		static int s; // 정적 멤버 변수는 클래스 내에 정의한다
	public:
		c_prac(int num, int *arr); //생성자
		c_prac(const c_prac &origin); //복사 생성자
		void	show_val();
		int		get_a_val() const;
		int		*get_b_arr() const;
		void	set_arr_val();
		c_prac &operator=(const c_prac &ref); // 대입 연산자 오버로딩
		static int	get_static(); // 정적 멤버 변수 get
		static void	show_static(); // 정적 멤버 변수 출력
		static void	set_static(int num); // 정적 멤버 변수 설정
};

// 클래스 외부에서 정적 멤버 변수를 선언한다. 
int	c_prac::s = 0;

// 대입 연산자 오버로딩
c_prac& c_prac::operator=(const c_prac &ref) //c1의 상수 참조를 매개변수로 받음
{
	std::cout << BOLDGREEN << "Copy assignment operator called" << std::endl;
	std::cout << BOLDYELLOW;
	std::cout << "pointer of this : " << this << std::endl;
	std::cout << "pointer of ref : " << &ref << std::endl;
	if (this != &ref)
	{
		this->a = ref.get_a_val();
		this->b = ref.get_b_arr();
	}
	return (*this); //c2의 참조 반환, 참조화는 자동으로 이루어짐
}

// 클래스 생성자
c_prac::c_prac(int num, int *arr) 
{
	std::cout << BOLDWHITE << "constructor called" << std::endl;
	this->a = num;
	this->b = arr;
	arg++;
}

// 클래스 복사 생성자 
c_prac::c_prac(const c_prac &ref) //매개 변수로 클래스의 상수 참조를 받음(c1의 상수 참조)
{
	std::cout << BOLDBLUE << "Copy constructor called" << std::endl;
	*this = ref; //c3은 c1의 메모리 주소를 공유
}

// 정적 멤버 변수 확인
void	c_prac::show_static()
{
	std::cout << "static : " << c_prac::s << std::endl;
}

// 정적 멤버 변수 설정
void	c_prac::set_static(int num)
{
	c_prac::s = num;
}

// 정적 멤버 변수 반환
int	c_prac::get_static()
{
	return (s);
}

// 멤버 함수들
void	c_prac::show_val()
{
	std::cout << "num : " << this->a << ' ' << "arr : ";
	for(int i = 0; i < 5; i++)
		std::cout<<this->b[i]<< ' ';
	std::cout<<std::endl;
	std::cout << "전역 : " << arg;
	std::cout<<std::endl;
}

void	c_prac::set_arr_val()
{
	this->b[2] = 2;
}

int	c_prac::get_a_val() const
{
	return (this->a);
}

int	*c_prac::get_b_arr() const
{
	return (this->b);
}

// 구조체 초기화
void	init_prac(t_prac *prac)
{
	std::cout << BOLDCYAN << "구조체 초기화" << std::endl;
	prac->a = 0;
	prac->b = (int *)malloc(sizeof(int) * 5);
	memset(prac->b, 0, 5);
}

// 구조체 복사;
t_prac	copy_prac(t_prac *prac)
{
	t_prac	copied;

	std::cout << BOLDYELLOW << "구조체 얕은 복사" << std::endl;
	copied.a = prac->a;
	copied.b = prac->b;
	return (copied);
}

// main functions
int main(void)
{
	t_prac	t1;
	t_prac	t2;

	init_prac(&t1);
	t2 = t1;
	std::cout << "구조체 대입 연산 실행(t2)" << std::endl;
	t_prac t3 = copy_prac(&t1);
	std::cout << "구조체 복사 생성(t3)" << std::endl;
	std::cout << std::endl;

	int		arr[5] = {1, 2, 3, 4, 5};

	std::cout << std::endl;
	c_prac::show_static();
	c_prac::set_static(200);
	c_prac::show_static();
	std::cout << std::endl;

	c_prac	c1(10, arr);
	std::cout << "클래스 c1 생성" << std::endl;
	c_prac	c3(c1); // 복사 생성자 호출
	std::cout << "c3 -> 복사 생성자 호출 ( c3(c1) )" << std::endl;
	c_prac	c2(0, NULL);
	std::cout << "클래스 c2 생성 후 대입 연산 실행" << std::endl;
	c2 = c1; //대입 생성자 오버로딩 호출
	std::cout << "c2 -> 대입 생성자 오버로딩 호출( c2 = c1 )" << std::endl;

	std::cout << BOLDRED;
	std::cout << "pointers(c1) : " << &c1 << std::endl;
	std::cout << "pointers(c2) : " << &c2 << std::endl;
	std::cout << "pointers(c3) : " << &c3 << std::endl;
	
	std::cout << BOLDWHITE << std::endl;
	std::cout << "t1 : ";
	for(int i = 0; i < 5; i++)
		std::cout<<t1.b[i]<<' ';

	std::cout << std::endl;

	std::cout << "t2 : ";
	for(int i = 0; i < 5; i++)
		std::cout<<t2.b[i]<<' ';

	std::cout << std::endl;

	std::cout << "t3 : ";
	for(int i = 0; i < 5; i++)
		std::cout<<t3.b[i]<<' ';

	std::cout << std::endl;

	t2.b[2] = 2;
	std::cout << std::endl;
	std::cout << BOLDRED << "구조체에 있는 배열의 2번째 인덱스를 2로 변경" << std::endl << std::endl;
	std::cout << BOLDBLUE;
	std::cout << "t1 : ";
	for(int i = 0; i < 5; i++)
		std::cout<<t1.b[i]<<' ';

	std::cout << std::endl;

	std::cout << "t2 : ";
	for(int i = 0; i < 5; i++)
		std::cout<<t2.b[i]<<' ';

	std::cout << std::endl;

	std::cout << "t3 : ";
	for(int i = 0; i < 5; i++)
		std::cout<<t3.b[i]<<' ';

	std::cout << std::endl << std::endl;
	std::cout << BOLDWHITE;
	std::cout << "c1-> "; 
	c1.show_val();
	std::cout << "c2-> ";
	c2.show_val();
	std::cout << "c3-> ";
	c3.show_val();

	c1.set_arr_val();
	std::cout << std::endl;
	std::cout << BOLDRED << "클래스에 있는 배열의 2번째 인덱스를 2로 변경" << std::endl;
	arg = 0; //전역 변수를 실수로 0으로 바꿔버릴 수도 있다
	std::cout << "클래스에서 다루는 전역 변수를 실수로 0으로 변경" << std::endl << std::endl;

	std::cout <<BOLDBLUE;
	std::cout << "c1-> "; 
	c1.show_val();
	std::cout << "c2-> "; 
	c2.show_val();
	std::cout << "c3-> ";
	c3.show_val();
}

