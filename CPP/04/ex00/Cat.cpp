/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:57:32 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 00:04:18 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat is appeared." << std::endl;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Copy Cat is appeared." << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& rhs)
{
    this->type = rhs.getType();
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat is disappeared." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "야옹야옹" << std::endl;
}