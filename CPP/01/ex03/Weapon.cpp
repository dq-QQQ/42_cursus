/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:42:41 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 18:47:10 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
    this->weapon = str;
}

const std::string & Weapon::getType() const
{
    return this->weapon;
}

void Weapon::setType(std::string weapon_type)
{
    this->weapon = weapon_type;
}