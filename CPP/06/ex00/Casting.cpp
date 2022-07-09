/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casting.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:32 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 17:56:27 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Casting.hpp"

Casting::Casting() {}

Casting::Casting(char* str) { value = atof(str); }

Casting::Casting(const Casting& other) { *this = other; }

Casting& Casting::operator=(const Casting& rhs) { this->value = rhs.getValue(); return *this; }

Casting::~Casting() {}

double Casting::getValue() const { return this->value; }

void Casting::printChar() const 
{
    if (!(this->value >= CHAR_MIN && this->value <= CHAR_MAX))
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value > 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void Casting::printInt() const
{
    if (value >= INT_MIN && value <= INT_MAX)
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void Casting::printFloat() const
{
    std::cout << "float: "<< std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void Casting::printDouble() const
{
    std::cout << "double: "<< std::fixed << std::setprecision(1)  << value << std::endl;
}