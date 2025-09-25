#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <typeinfo>
#include <cstdlib>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define NC "\033[0m"

class Base {
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate(void);

void	identify(Base* p);

void	identify(Base& p);

#endif