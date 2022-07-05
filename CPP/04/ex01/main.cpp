/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:58:59 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 00:12:50 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog;
	delete cat;

	std::cout << "\n\n---------------my test----------\n\n";
	Animal *animal[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		std::cout << "\n";
	}
	
	std::cout << "\n\n--------get type test--------\n";
	for (int i = 0; i < 10; i++)
		std::cout << i << " : " << animal[i]->getType() << std::endl;

	std::cout << "\n\n--------set brain test--------\n";
	for (int i = 0; i < 10; i++)
		animal[i]->getBrain()->setIdeas("ho", 0);
	for (int i = 0 ; i < 10; i++)
		std::cout << animal[i]->getBrain()->getIdeas(0) << std::endl;
	
	std::cout << "\n\n--------delete test--------\n";
	for (int i = 0; i < 10; i++)
	{
		delete animal[i];
		std::cout << "\n";
	}
	return 0;
}