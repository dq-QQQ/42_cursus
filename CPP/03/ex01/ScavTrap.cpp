/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:57:21 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 23:26:55 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "[ScavTrap] unknown is created." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
    std::cout << "[ScavTrap]" << this->name << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	this->name = rhs.getName();
    this->hp = rhs.getHp();
    this->ep = rhs.getEp();
    this->ad = rhs.getAd();
	return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ScavTrap]" << this->name << " is deleted." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (ep == 0)
    {
        std::cout << "energy point is zero" << std::endl;
        return ;
    }
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
	ep--;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << "is now in Gate keeper mode. " << std::endl;
}