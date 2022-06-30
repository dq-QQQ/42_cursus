/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:17:35 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 19:33:32 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    weapon_type = NULL;
}

void HumanB::attack() const
{
    std::cout << this->name << " attacks with their " << this->weapon_type->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon_type = &weapon;
}