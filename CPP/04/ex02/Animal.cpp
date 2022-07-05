/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:01:04 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 00:14:42 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    this->type = "";
	std::cout << "Animal is appeared." << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy Animal is appeared." << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& rhs)
{
	this->type = rhs.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal is disappeared." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}