#include "ScalarConverter.h"
#include <cmath>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)other;
    *this = other;

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    if (this != &other)
    {
        *this = other;
        std::cout << "Copying state from other ScalarConverter" << std::endl;          

    }
    return *this;
}


static bool isPseudoLiteral(const string &str)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
        return true;
    return false;
}

static void printPseudoLiteral(const string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
    }
    else
    {
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
    }
}


static double stringToDouble(const std::string& s) {
    std::istringstream iss(s);
    double d;
    iss >> d;
    return d;
}

static float stringToFloat(const std::string& s) {
    std::istringstream iss(s);
    float f;
    iss >> f;
    return f;
}

static int stringToInt(const std::string& s) {
    std::istringstream iss(s);
    int i;
    iss >> i;
    return i;
}


static void printValues(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    
    std::cout << "int: ";
    if (std::isnan(value) ||
        value > static_cast<double>(std::numeric_limits<int>::max()) ||
        value < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f" << std::endl;

    
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << value << std::endl;
}


void ScalarConverter::convert(string &input) {
    double value;

    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        char c = input[1];
        value = static_cast<double>(c);
    }
    else if (isPseudoLiteral(input)) {
        printPseudoLiteral(input);
        return;
    }
    else if (input[input.length() - 1] == 'f') {
        value = stringToFloat(input);
    }
    else if (input.find('.') != std::string::npos) {
        value = stringToDouble(input);
    }
    else {
        value = static_cast<double>(stringToInt(input));
    }
    printValues(value);
   
}

    