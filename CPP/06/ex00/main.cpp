/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:45 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 17:46:57 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Casting.hpp"


int main(int argc, char** argv)
{
    if (argc != 2)
        return 0;
    
    Casting c(argv[1]);
    c.printChar();
    c.printInt();
    c.printFloat();
    c.printDouble();
    
}