/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:57:32 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/07 00:57:48 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    brain = new Brain;
    this->type = "Cat";
    std::cout << "Cat is appeared." << std::endl;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Copy Cat is appeared." << std::endl;
    this->type = other.getType();
    this->brain = new Brain;
    *(this->brain) = *(other.brain);
}

Cat& Cat::operator=(const Cat& rhs)
{
    this->type = rhs.getType();
    *(this->brain) = *(rhs.brain);
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat is disappeared." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "야옹야옹" << std::endl;
}

void Cat::printIdeas(int i) const
{
    std::cout << brain[i].getIdeas(i) << std::endl;
}

void Cat::setIdeas(int i, std::string idea)
{
    brain[i].setIdeas(idea, i);
}