/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:58:28 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 18:24:05 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce() const
{
    std::cout << this->name << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}