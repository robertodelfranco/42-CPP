/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:08:27 by marvin            #+#    #+#             */
/*   Updated: 2025/08/28 22:08:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << WHITE << "------------------------" << NC << std::endl;
	std::cout << WHITE << "     RIGHT ANIMALS" << NC << std::endl;
	std::cout << WHITE << "------------------------" << NC << std::endl;
	std::cout << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << std::endl;
	
	meta->makeSound();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << std::endl;
	dog->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << std::endl;
	cat->makeSound();
	std::cout << cat->getType() << " " << std::endl;

	std::cout << std::endl;
	
	delete cat;
	delete dog;
	delete meta;

	std::cout << std::endl;
	std::cout << WHITE << "------------------------" << NC << std::endl;
	std::cout << WHITE << "     WRONG ANIMALS" << NC << std::endl;
	std::cout << WHITE << "------------------------" << NC << std::endl;
	std::cout << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << std::endl;
	
	wrongMeta->makeSound();
	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << std::endl;
	wrongCat->makeSound();
	std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << std::endl;

	delete wrongMeta;
	delete wrongCat;

	return 0;
}
