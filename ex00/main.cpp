#include "ScalarConverter/ScalarConverter.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input>" << std::endl;
        return 1;
    }

    std::string input(argv[1]);
    ScalarConverter::convert(input);

    return 0;
}