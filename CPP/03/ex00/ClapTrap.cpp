/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:26:50 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/04 22:46:00 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
{
    this->name = "unknown";
    this->hp = 10;
    this->ep = 10;
    this->ad = 0;
    std::cout << "unknown is created." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hp = 10;
    this->ep = 10;
    this->ad = 0;
    std::cout << this->name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    this->name = rhs.getName();
    this->hp = rhs.getHp();
    this->ep = rhs.getEp();
    this->ad = rhs.getAd();
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " is deleted." << std::endl;
}

std::string ClapTrap::getName() const
{
    return this->name;
}

int ClapTrap::getHp() const
{
    return this->hp;
}

int ClapTrap::getEp() const
{
    return this->ep;
}

int ClapTrap::getAd() const
{
    return this->ad;
}

void ClapTrap::setName(std::string *name)
{
    this->name = *name;
}

void ClapTrap::setHp(int *hp)
{
    this->hp = *hp;
}

void ClapTrap::setEp(int *ep)
{
    this->ep = *ep;
}

void ClapTrap::setAd(int *ad)
{
    this->ad = *ad;
}

void ClapTrap::attack(const std::string& target)
{
    if (ep == 0)
    {
        std::cout << "energy point is zero" << std::endl;
        return ;
    }
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << ad << " points of damage!" << std::endl;
	ep--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takeDamage : " << amount << std::endl;
	if ((unsigned int)hp < amount)
		hp = 0;
	else
		hp -= amount;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (ep == 0)
    {
        std::cout << "energy point is zero" << std::endl;
        return ;
    }
	std::cout << "ClapTrap " << name << " repaired : " << amount << std::endl;
	hp += amount;
	ep--;
}

std::ostream& operator<<(std::ostream& out, const ClapTrap& rhs)
{
    out << "Name :" << rhs.getName() << std::endl 
        << "Hit Points : " << rhs.getHp() << std::endl
        << "Energy Points : " << rhs.getEp() << std::endl
        << "Attack Damage : " << rhs.getAd() << std::endl;
    return out;
}