/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:11:21 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 00:02:32 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "";
	std::cout << "WrongAnimal is appeared." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy WrongAnimal is appeared." << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	this->type = rhs.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal is disappeared." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}