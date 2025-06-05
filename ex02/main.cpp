#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "utils.hpp"

int main(void)
{
	Base *test = generate();
	
	identify(*test);

	delete test;
}
