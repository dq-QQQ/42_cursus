/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:18:39 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/29 01:17:16 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
    Contact contact[8];
    int idx;
public:
    PhoneBook();
    void add();
    std::string truncate(std::string s);
    void search();
    void exit();
};