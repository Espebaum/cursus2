#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Serializer  s;
	Data		d;
	uintptr_t	ptr_t;

    initData(d);

    std::cout<<BOLDBLUE<<"     > Information of Struct Data < "<<std::endl;
    std::cout<<d<<std::endl;

    std::cout<<"-----------------------------------------"<<std::endl;
	std::cout<<BOLDCYAN<<"Pointer of Data : "<<RESET<<&d<<std::endl;
	
    ptr_t = s.serialize(&d);

	std::cout<<BOLDYELLOW<<"After Serialization : "<<RESET<<ptr_t<<std::endl;
    std::cout<<BOLDMAGENTA<<"Hexed Output : "<<RESET<<"0x"<<std::hex<<ptr_t<<std::endl;

    Data* d_Ptr = s.deserialize(ptr_t);
    
    if (!ptr_t)
        Serializer::setStatic(false);
    
    std::cout<<BOLDBLUE<<"After Deserialization : "<<RESET<<d_Ptr<<std::endl;

    if (Serializer::getStatic())
        std::cout<<BOLDGREEN<<" => Deserialization successful!"<<RESET<<std::endl;
    else
        std::cout<<BOLDRED <<" => Deserialization failed!"<<RESET<<std::endl;

	std::cout<<"-----------------------------------------"<<std::endl;
    std::cout<<BOLDBLUE<<"  > Information of Copied Struct Data < "<<std::endl;
    std::cout<<*d_Ptr<<std::endl;
}
