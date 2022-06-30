/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:29:55 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 14:55:32 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zom;

    // in heap
    zom = newZombie("kyujlee in heap");
    zom->announce();
    delete zom;

    // in stack
    randomChump("kyujlee in stack");
}