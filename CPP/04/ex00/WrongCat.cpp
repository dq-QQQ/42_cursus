/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:16:13 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 00:03:14 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat is appeared." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "Copy WrongCat is appeared." << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    this->type = rhs.getType();
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat is disappeared." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "야옹야옹" << std::endl;
}