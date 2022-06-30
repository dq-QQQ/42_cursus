/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:08:33 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 18:23:39 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::set_name(std::string name)
{
    this->name = name;
}

void Zombie::announce() const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}