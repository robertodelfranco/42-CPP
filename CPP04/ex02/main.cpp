/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:08:27 by marvin            #+#    #+#             */
/*   Updated: 2025/08/29 19:15:55 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {	
	const Animal* meta[5];

	for (int i = 0; i < 5; i++) {
		if (i < 3)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << WHITE << "------------------------" << NC << std::endl;
	std::cout << WHITE << "      COPY ANIMALS" << NC << std::endl;
	std::cout << WHITE << "------------------------" << NC << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Dog* dogOne = new Dog();
	dogOne->setIdea(0, "testing wolf!");
	Dog* dogTwo = new Dog(*dogOne);

	Cat* catOne = new Cat();
	catOne->setIdea(0, "testing meow!");
	Cat* catTwo = new Cat(*catOne);
	
	delete catOne;
	delete dogOne;
	
	dogTwo->makeSound();
	catTwo->makeSound();
	
	std::cout << dogTwo->getIdea(0) << std::endl;
	std::cout << catTwo->getIdea(0) << std::endl;
	
	meta[0]->makeSound();
	meta[2]->makeSound();
	meta[3]->makeSound();
	meta[4]->makeSound();
	
	delete catTwo;
	delete dogTwo;

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		delete meta[i];

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << WHITE << "------------------------" << NC << std::endl;
	std::cout << WHITE << "       BRAIN TESTS" << NC << std::endl;
	std::cout << WHITE << "------------------------" << NC << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Brain* b = new Brain();
	
	b->setIdea(1, "TEST ONE");
	b->setIdea(4, "TEST TWO");
	b->setIdea(5, "TEST THREE");
	std::cout << b->getIdea(1) << std::endl;
	std::cout << b->getIdea(4) << std::endl;
	std::cout << b->getIdea(5) << std::endl;
	std::cout << b->getIdea(3) << std::endl;

	delete b;

	return 0;
}
