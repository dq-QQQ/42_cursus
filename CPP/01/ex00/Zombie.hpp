/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:08:36 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 18:23:25 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    void set_name(std::string name);
    void announce() const; 
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);