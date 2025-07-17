#include "Base.h"
#include "../A.h"
#include "../B.h"
#include "../C.h"

Base::~Base()
{
    std::cout << "Base destructor called." << std::endl;
}



Base *Base::generate(void)
{
    int rand = std::rand() %3;

    switch (rand)
    {
    case 0:
        std::cout << "Generating A object." << std::endl;
        return new A();
    case 1:
        std::cout << "Generating B object." << std::endl;
        return new B();
    default:
        std::cout << "Generating C object." << std::endl;
        return new C();
    }
    return NULL;
}


void Base::identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identified as A." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified as B." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified as C." << std::endl;
    else
        std::cout << "Unknown type." << std::endl;
}

void Base::identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified as A&." << std::endl;
        return;
    }
    catch(const std::exception& e){}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified as B&." << std::endl;
        return;
    }
    catch(const std::exception& e){}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified as C&." << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cout << "Unknown type&." << std::endl;
    }
}



// void Base::identify(Base &p)
// {
//     identify(&p);
// }