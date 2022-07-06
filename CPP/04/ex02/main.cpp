/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:58:59 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/07 01:05:24 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	// Animal *ani = new Animal();
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

	
	std::cout << "\n\n--------delete test--------\n";
	for (int i = 0; i < 10; i++)
	{
		delete animal[i];
		std::cout << "\n";
	}
	
	Cat c;
	Cat d (c);
	Cat e = c;

	std::cout << "\n\n--------deep copy test--------\n";
	c.setIdeas(0, "ho");
	d.setIdeas(0, "ho2");
	e.setIdeas(0, "ho3");
	c.printIdeas(0);
	d.printIdeas(0);
	e.printIdeas(0);
	
	return 0;
}