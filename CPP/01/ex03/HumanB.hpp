/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:14:55 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 19:33:34 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon_type;
public:
    HumanB(std::string name);
    void attack() const;
    void setWeapon(Weapon &weapon);    
};