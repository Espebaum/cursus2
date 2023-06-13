#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <typeinfo>

int main(void)
{
    Base    *bp = generate();    
    std::cout<<bp<<std::endl;

    const std::type_info& type = typeid(bp);
    std::cout << "Type : " << type.name() << std::endl;

    delete bp;

    return 0;
}
