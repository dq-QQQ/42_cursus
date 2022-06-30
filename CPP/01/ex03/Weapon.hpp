/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:39:00 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 18:46:55 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon
{
private:
    std::string weapon;
public:
    Weapon(std::string str);
    const std::string &getType() const;
    void setType(std::string weapon_type);
};