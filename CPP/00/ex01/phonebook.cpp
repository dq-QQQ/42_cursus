/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:18:26 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 13:32:50 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook()
{
    this->idx = 0;
}

void PhoneBook::add()
{
    std::string tmp;
    
    std::cout << "first_name : ";
    std::cin >> tmp;
    if (check_flag())
        return ;
    contact[idx].set_first_name(tmp);

    std::cout << "last_name : ";
    std::cin >> tmp;
    if (check_flag())
        return ;
    contact[idx].set_last_name(tmp);

    std::cout << "nickname : ";
    std::cin >> tmp;
    if (check_flag())
        return ;
    contact[idx].set_nickname(tmp);

    std::cout << "phone : ";
    std::cin >> tmp;
    if (check_flag())
        return ;
    contact[idx].set_phone(tmp);

    std::cout << "secret : ";
    std::cin >> tmp;
    if (check_flag())
        return ;
    contact[idx].set_secret(tmp);
    if (idx == 7)
        idx = 0;
    else
        idx++;
    std::cout << std::endl;
}

std::string PhoneBook::truncate(std::string s)
{
    if (s.size() > 10)
    {
        s[9] = '.';
        return s.substr(0, 10);
    }
    else
        return s;
}

void PhoneBook::search()
{
    int i;

    std::cout << "index : ";
    std::cin >> i;
    if (check_flag())
        return ;
    if (i > 8)
    {
        std::cout << "Input under 8" << std::endl;
    }
    else
    {
        std::cout << std:: endl << std::setw(11) << "Index|";
	    std::cout << std::setw(11) << "Name|";
	    std::cout << std::setw(11) << "Lastname|";
	    std::cout << std::setw(11) << "Nickname|";
	    std::cout << std::endl;
	    std::cout << "--------------------------------------------" << std::endl;
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(contact[i - 1].get_first_name()) << "|";
        std::cout << std::setw(10) << truncate(contact[i - 1].get_last_name()) << "|";
        std::cout << std::setw(10) << truncate(contact[i - 1].get_nickname()) << "|" << "\n\n";
    }
}

void PhoneBook::exit()
{
    std::exit(0);
}