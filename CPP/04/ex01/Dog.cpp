/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:51:26 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/07 00:58:06 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    brain = new Brain;
    this->type = "Dog";
    std::cout << "Dog is appeared." << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Copy Dog is appeared." << std::endl;
    this->type = other.getType();
    this->brain = new Brain;
    *(this->brain) = *(other.brain);
}

Dog& Dog::operator=(const Dog& rhs)
{
    this->type = rhs.getType();
    *(this->brain) = *(rhs.brain);
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog is disappeared." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "멍멍" << std::endl;
}


void Dog::printIdeas(int i) const
{
    std::cout << brain[i].getIdeas(i) << std::endl;
}

void Dog::setIdeas(int i, std::string idea)
{
    brain[i].setIdeas(idea, i);
}