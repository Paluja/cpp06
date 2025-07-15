#ifndef SERIALIZER_H
#define SERIALIZER_H

#pragma once

#include <iostream>
#include <string>

typedef unsigned long uintptr_t; 

typedef struct Data
{
    std::string str;
} Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer&); // Disable copy constructor
        Serializer& operator=(const Serializer&); // Disable copy assignment operator
        ~Serializer();
        
    public:

        static uintptr_t serialize(Data* ptr); 
        static Data *deserialize(uintptr_t raw);
        


};

#endif