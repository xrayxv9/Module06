#pragma once

#include <iostream>

#define STRING 1
#define FLOAT 2
#define DOUBLE 3
#define CHAR 4

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter( const ScalarConverter &cpy );
		~ScalarConverter();
		ScalarConverter& operator=( const ScalarConverter &cpy );
		static void convert(std::string toConvert);

	private:
		static void print( char letter );
		static void print( std::string );
};
