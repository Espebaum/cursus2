#include <iostream>

class explicito
{
	private:
		int	ex;
	public:
		explicito() {};
	
		// --- Constructors --- //
		explicito(int num) {
			ex = num + 1;
		};

		explicito(std::string str) {
			ex = static_cast<int>(str.length()); 
		}

		// --- Constructor with Keyword Explicit --- //
		// explicit	explicito(int num) {
		//     ex = num + 1;
		// };

		// explict	explicito(std::string str) {
		//     ex = static_cast<int>(str.length());
		// }

		int	getEx() const {
			return (this->ex);
		}

		int	getStrLen(std::string strEx) {
			return (static_cast<int>(strEx.length()));
		};

		explicito(const explicito& ref);
		explicito& operator=(const explicito& ref);
};

int	plusOneWithInt(explicito ex)
{
	int size = ex.getEx();
	return (++size);
}

int	main(void)
{
	std::cout<<plusOneWithInt(5)<<std::endl;
	// plusOne은 클래스 explicito를 매개변수로 받지만
	// 여기에 정수 int를 넘겨줘도 암시적 변환(Implicit Conversion)을 통해
	// 클래스 explicito에서 int를 매개변수로 받는 생성자를 찾아서 함수를 실행한다.

	std::string		str = "hey";

	std::cout<<plusOneWithInt(str)<<std::endl;
	// 그러나 암시적 변환이 반드시 편리한 것만은 아니다. plusOneWithInts는
	// Int를 매개변수로 받아 1을 더해 반환하는 것을 상정하고 만들어진 함수이다.
	// 따라서 string을 매개변수로 받는 것은 의도하지 않은 상황이다. 이 경우
	// 원하는 않는 암시적 변환을 하지 않도록 컴파일러에 명시할 수 있는데
	// 그것이 바로 explicit 키워드이다.

	explicito	ex1 = 9; // explicito	ex1(9);
	// 또한 explicit 키워드는 복사 생성자의 변환 또한 막는다.
	// 즉 명시적으로 생성자를 호출하지 않는 모든 행위 또한 막는다고 볼 수 있다.

	std::cout<<ex1.getEx()<<std::endl;
}
