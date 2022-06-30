/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:58:31 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 18:23:53 by kyujlee          ###   ########.fr       */
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

Zombie* zombieHorde( int N, std::string name );