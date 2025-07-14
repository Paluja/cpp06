#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H


#include <iostream>
#include <string>
#include <sstream>

typedef std::string string;

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    static void convert(string &input);
    ~ScalarConverter();

private:

};

#endif