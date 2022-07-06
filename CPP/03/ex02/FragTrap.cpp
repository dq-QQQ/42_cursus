/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:13:13 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/04 23:19:16 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "[FragTrap] unknown is created." << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
    std::cout << "[FragTrap]" << this->name << " is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	this->name = rhs.getName();
    this->hp = rhs.getHp();
    this->ep = rhs.getEp();
    this->ad = rhs.getAd();
	return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "[FragTrap]" << this->name << " is deleted." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests positive high fives. " << std::endl;
}