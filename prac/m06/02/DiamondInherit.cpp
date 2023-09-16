#include <iostream>

class A
{
public:
    virtual ~A() {}
};

class B : public A {};

class C : public A {};

class D : public B, public C {};

int main()
{
    D d;
    B* b_ptr = &d;
    C* c_ptr = &d;

    if (dynamic_cast<A*>(b_ptr) == dynamic_cast<A*>(c_ptr))
        std::cout << "Same" << std::endl;
    else
        std::cout << "Not Same" << std::endl;

    return 0;
}
