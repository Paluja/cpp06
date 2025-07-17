#ifndef BASE_H
#define BASE_H

#pragma once

#include <iostream>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base();
        Base *generate(void);
        void identify(Base *p);
        void identify(Base &p);
};

#endif 