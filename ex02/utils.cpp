#include "utils.hpp"
#include <typeinfo>

Base *generate()
{
	srand(time(0));
	int random = rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "A" << std::endl;
			return new A();
		case 1:
			std::cout << "B" << std::endl;
			return new B();
		case 2:
			std::cout << "C" << std::endl;
			return new C();
	}
	return new (A);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The A was generated" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The B was generated" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The C was generated" << std::endl;
}

void identify(Base& p)
{
	Base tmp;

	try
	{
		tmp = dynamic_cast<A&>(p);
		std::cout << "The A was generated" << std::endl;
	}
	catch (std::bad_cast &e)
	{}

	try
	{
		tmp = dynamic_cast<B&>(p);
		std::cout << "The B was generated" << std::endl;
	}
	catch (std::bad_cast &e)
	{}
	try
	{
		tmp = dynamic_cast<C&>(p);
		std::cout << "The C was generated" << std::endl;
	}
	catch (std::bad_cast &e)
	{}
}
