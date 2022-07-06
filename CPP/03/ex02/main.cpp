/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:26:47 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/04 23:17:48 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap a ("A");
    FragTrap b ("B");

    std::cout << std::endl << "------------A-----------" << std::endl << a << std::endl;
    std::cout << "------------B-----------" << std::endl << b << std::endl;

    a.attack("B");
    b.takeDamage(a.getAd());

    std::cout << std::endl << "------------A-----------" << std::endl << a << std::endl;
    std::cout << "------------B-----------" << std::endl << b << std::endl;
    
    b.beRepaired(1);

    std::cout << std::endl << "------------A-----------" << std::endl << a << std::endl;
    std::cout << "------------B-----------" << std::endl << b << std::endl;

    a.highFivesGuys();
}