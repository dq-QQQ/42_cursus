/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:18:34 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/29 01:28:46 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(int argc , char **argv)
{
    PhoneBook pb;
    std::string cmd;

    while (1)
    {
        std::cout << "COMMAND : ";
        std::cin >> cmd;
        std::cout << std::endl;
        if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            pb.exit();
    }
    return 0;
}