#include "MutantStack.hpp"

int main() {
	std::cout << WHITEBOLD << "----- MutantStack -----" << RESET << std::endl;
	std::cout << std::endl;
	
	MutantStack<int> mstack;
	std::cout << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;
	
	mstack.pop();

	std::cout << "Top after pop: " << mstack.top() << std::endl;
	
	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << YELLOW << *it << RESET << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout << WHITEBOLD << "----- Container List -----" << RESET << std::endl;
	std::cout << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Back/Top: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Back/Top after pop: " << lst.back() << std::endl;

	std::cout << "Size: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	++lit;
	--lit;
	while (lit != lite) {
		std::cout << YELLOW << *lit << RESET << std::endl;
		++lit;
	}

	std::cout << std::endl;

	return 0;
}