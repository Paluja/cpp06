#include "Base/Base.h"



int main(void)
{
    Base *basePtr = Base().generate();
    
    std::cout << "Generated object pointer: " << basePtr << std::endl;
    
    // Identify the type of the generated object
    basePtr->identify(basePtr);
    basePtr->identify(*basePtr);
    // Clean up
    delete basePtr;

    return 0;
}