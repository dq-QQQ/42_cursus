/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:26:37 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 18:34:06 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    const std::string str = "HI THIS IS BRAIN";
    const std::string *stringPTR = &str;
    const std::string &stringREF = str;

    std::cout << "The memory address by string variable : "<< &str << std::endl;
    std::cout << "The memory address by stringPTR       : " << stringPTR << std::endl;
    std::cout << "The memory address by stringREF       : " << &stringREF << "\n\n";

    std::cout << "The value of the string variable  : " << str << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;
}