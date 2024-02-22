#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	int i = rand() % 3;

	if (i == 0)
	{
		std::cout << "A class generated" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "B class generated" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C class generated" << std::endl;
		return new C;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "*A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "*B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "*C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "&A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "&B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "&C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main(void)
{

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Test " << i + 1 << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << "---------------" << std::endl;
	}
	return 0;
}