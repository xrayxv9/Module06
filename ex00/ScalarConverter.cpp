#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>

/*
		void printChar( char c, bool valid );
		void printInt( int c, bool valid );
		void printDouble( double c, bool valid );
		void printFloat( float c, bool valid );

* */


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

bool checkText(std::string input)
{
	std::string texts[6] = {
			"inff",
			"-inff",
			"inf",
			"-inf",
			"nan",
			"nanf"
	};

	for (int i = 0; i < 6; i++)
		if (texts[i] == input)
			return true;
	return false;
}

void	printChar(char c, bool valid)
{
	if (!valid)
	{
		std::cout << "char : Impossible" << std::endl;
		return ;
	}
	if (c >= 32)
		std::cout << "char : " << c << std::endl;
	else
		std::cout << "char : " << "character not printable" << std::endl;
}

void printInt(int n, bool valid)
{
	if (!valid)
	{
		std::cout << "int : Impossible" << std::endl;
		return ;
	}
	std::cout << "int : " << n << std::endl;
}

void printDouble(int n, bool valid)
{
	if (!valid)
	{
		std::cout << "double : Impossible" << std::endl;
		return ;
	}
	std::cout << "double : " << n << std::endl;
}

void printFloat(int n, bool valid)
{
	if (!valid)
	{
		std::cout << "float : Impossible" << std::endl;
		return ;
	}
	std::cout << "float : " << n << "f" << std::endl;
}

void printNonLitteral( std::string input )
{
	printChar('c', false);
	printInt(0, false);
	if ( input == "-inff" || input == "inff" || input == "nanf")
	{
		std::cout << "float : " << input << std::endl;
		std::cout << "double : " << input.substr(0, input.length() - 1) << std::endl;
	}
	else 
	{
		std::cout << "float : " << input << "f" << std::endl;
		std::cout << "double : " << input << std::endl;
	}
}

static bool isValid( std::string input )
{
	int dotCounter = 0;
	int	nbF = 0;
	int nbSigns = 0;
	int i = 0;

	// check if there is one character because it should always be good
	if (input.length() == 1)
		return true;

	// check to see if he didn't give me anything (which should not be possible)
	if (input.empty())
		return false;

	if (checkText(input))
		return true;

	// check to see if there are multiple dots
	while (input[i] && dotCounter < 2)
	{
		if (!std::isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '.' && input[i] != 'f')
			return false;
			
		if (input[i] == '.')
			dotCounter++;
		else if (input[i] == '+' || input[i] == '+')
			nbSigns++;
		else if (input[i] == 'f')
			nbF++;
		i++;
	}

	if (dotCounter > 1 || nbSigns > 1 || nbF > 1)
		return false;

	return true;
}

void fromFloat( std::string input )
{
	char *end;
	float num = std::strtof(input.c_str(), 0);
	int full = static_cast<int>(num);
	char c = static_cast<char>(num);
	double doubleNumber = static_cast<double>(num);

	printChar(c, true);
	printInt(full, true);
	if (num > FLT_MAX || num < FLT_MIN || errno == ERANGE)
		printFloat(num, false);
	else 
		printFloat(num, true);
	printDouble(doubleNumber, true);
}

void fromDouble( std::string input )
{
	// double num = std::atod(input.c_str());
	(void)input;
	float num = 2.3f;
	int full = static_cast<int>(num);
	char c = static_cast<char>(num);
	double doubleNumber = static_cast<double>(num);

	printChar(c, true);
	printInt(full, true);
	if (num > FLT_MAX || num < FLT_MIN || errno == ERANGE)
		printFloat(num, false);
	else 
		printFloat(num, true);
	printDouble(doubleNumber, true);
}

void ScalarConverter::convert( const std::string toConvert)
{
	if (!isValid(toConvert))
	{
		printChar('c', false);
		printInt(0, false);
		printFloat(0, false);
		printDouble(0, false);
	}

	if (checkText(toConvert))
	{
		printNonLitteral(toConvert);
		return ;
	}
	if (toConvert[toConvert.length() - 1] == 'f')
		fromFloat(toConvert);
		
}
