/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:51:26 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 00:04:00 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog is appeared." << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Copy Dog is appeared." << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& rhs)
{
    this->type = rhs.getType();
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog is disappeared." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "멍멍" << std::endl;
}