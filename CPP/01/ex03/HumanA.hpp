/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:47:26 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 19:13:19 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &weapon_type;
public:
    HumanA(std::string name, Weapon &weapon);
    void attack() const;
};