/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:13:57 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 13:30:43 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::set_first_name(std::string s)
{
    this->first_name = s;
}

void Contact::set_last_name(std::string s)
{
    this->last_name = s;
}

void Contact::set_nickname(std::string s)
{
    this->nickname = s;
}

void Contact::set_phone(std::string s)
{
    this->phone = s;
}

void Contact::set_secret(std::string s)
{
    this->secret = s;
}

std::string Contact::get_first_name()
{
    return this->first_name;
}

std::string Contact::get_last_name()
{
    return this->last_name;
}

std::string Contact::get_nickname()
{
    return this->nickname;
}

std::string Contact::get_phone()
{
    return this->phone;
}

std::string Contact::get_secret()
{
    return this->secret;
}