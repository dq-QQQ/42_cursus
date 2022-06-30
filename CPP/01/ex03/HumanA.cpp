/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:01:25 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 19:14:16 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon_type(weapon)
{
    this->name = name;
}

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their " << this->weapon_type.getType() << std::endl;
}

