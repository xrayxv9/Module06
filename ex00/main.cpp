#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "I would be thankful if you gave me one argument" << std::endl;
		return (0);
	}

	ScalarConverter::convert(argv[1]);
}
