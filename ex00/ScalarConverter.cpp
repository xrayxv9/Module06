#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter &cpy )
{
	if (this != &cpy)
		return *this;
	return *this;
}

ScalarConverter::ScalarConverter( const ScalarConverter &cpy )
{
	*this = cpy;
}

void ScalarConverter::print( char letter )
{
	std::cout << "char : " << letter<< std::endl;
	std::cout << "int : " << (int)letter << std::endl; 
	std::cout << "float : " << (float)letter << ".0f" << std::endl; 
	std::cout << "double : " << (double)letter << ".0" << std::endl; 
}

void ScalarConverter::print( std::string number)
{
	std::cout << "char : " << "Unknown" << std::endl;
	std::cout << "int : " << std::stoi(number)<< std::endl; 
	std::cout << "float : " << std::stof(number) << ".0f" << std::endl; 
	std::cout << "double : " << std::stod(number) << ".0" << std::endl; 
}

void ScalarConverter::convert( const std::string toConvert)
{
	int len = toConvert.length();
	
	if (len == 1 && std::isalpha(toConvert[0]))
		print('a');
	if (len < 13)
	{
		for (int i = 0; toConvert[i]; i++)
		{
			if ((int)toConvert[i] < (int)'0' || (int)toConvert[i] > '9')
			{
				std::cout <<  "error: other thing than numbers detected" << std::endl;
				return ;
			}
		}
		print()
	}
}
