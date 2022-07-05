/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:58:59 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 00:07:34 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "\n\n-----------wrong example------------\n\n";

	const WrongAnimal* w_meta = new WrongAnimal();

	const WrongAnimal* w_i = new WrongCat();

	std::cout << w_i->getType() << " " << std::endl;

	w_i->makeSound();
	w_meta->makeSound();

	delete w_meta;
	delete w_i;
	return 0;
}