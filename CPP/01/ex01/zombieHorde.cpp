/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:58:33 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 16:46:22 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zom;

    zom = new Zombie[N];
    for (int i = 0; i < N; i++)
        zom[i].set_name(name);
    
    return zom;
}