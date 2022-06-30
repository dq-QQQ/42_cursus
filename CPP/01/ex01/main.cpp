/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:18:34 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 13:35:01 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int check_flag()
{
    if (std::cin.eof() || std::cin.fail())
	{
		std::cin.clear();
		clearerr(stdin);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
	}
    return 0;
}

int main(int argc , char **argv)
{
    PhoneBook pb;
    std::string cmd;

    while (1)
    {
        std::cout << "COMMAND : ";
        std::cin >> cmd;
        std::cout << std::endl;
        if (check_flag())
            continue;
        if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            pb.exit();
    }
    return 0;
}