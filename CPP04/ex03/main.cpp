/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:02:00 by rdel-fra          #+#    #+#             */
/*   Updated: 2025/09/09 18:09:48 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main() {
	std::cout << "----------- BASIC TEST FROM SUBJECT -----------" << std::endl;
	std::cout << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << "\n----------- TESTING DEEP COPY OF CHARACTER -----------" << std::endl;
	std::cout << std::endl;
	
	// Test copy constructor
	Character* originalChar = new Character("original");
	originalChar->equip(src->createMateria("ice"));
	originalChar->equip(src->createMateria("cure"));
	
	std::cout << "\n- Testing Character copy constructor:" << std::endl;
	Character* copiedChar = new Character(*originalChar);
	
	std::cout << "\n- Testing original after copying:" << std::endl;
	originalChar->use(0, *bob);  // Should use ice
	originalChar->use(1, *bob);  // Should use cure
	
	std::cout << "\n- Testing copy after copying:" << std::endl;
	copiedChar->use(0, *bob);    // Should also use ice
	copiedChar->use(1, *bob);    // Should also use cure
	
	std::cout << "\n- Modifying original should not affect copy:" << std::endl;
	originalChar->unequip(0);
	originalChar->use(0, *bob);  // Should show empty slot
	copiedChar->use(0, *bob);    // Should still use ice
	
	std::cout << "\n- Testing Character assignment operator:" << std::endl;
	Character assignChar("assigned");
	assignChar = *originalChar;
	
	std::cout << "\n- Original and assigned after assignment:" << std::endl;
	originalChar->use(1, *bob);
	assignChar.use(1, *bob);
	
	std::cout << "\n----------- TESTING MATERIA SOURCE COPY -----------" << std::endl;
	std::cout << std::endl;

	MateriaSource* srcCopy = new MateriaSource(*(MateriaSource*)src);
	
	std::cout << "\n- Testing source copy:" << std::endl;
	tmp = srcCopy->createMateria("ice");
	if (tmp)
		std::cout << "Successfully created ice from copied source" << std::endl;
	delete tmp;
	
	std::cout << "\n----------- TESTING INVENTORY LIMITS -----------" << std::endl;
	std::cout << std::endl;
	
	Character fullChar("inventory_test");

	for (int i = 0; i < 6; i++) {
		tmp = src->createMateria("ice");
		if (tmp) {
			std::cout << "Equipping slot " << i << ": ";
			fullChar.equip(tmp);
		}
	}
	
	std::cout << "\n----------- CLEANUP -----------" << std::endl;
	std::cout << std::endl;
	
	delete bob;
	delete me;
	delete src;
	delete originalChar;
	delete copiedChar;
	delete srcCopy;

	return 0;
}
