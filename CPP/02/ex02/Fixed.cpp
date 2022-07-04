/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:40:42 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/04 11:25:05 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int n) : value(n << fractional) {}

Fixed::Fixed(const float f) : value(roundf(f * (1 << fractional))) {}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    this->value = rhs.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed& rhs) const
{
    return this->toFloat() > rhs.toFloat() ? true : false;
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return this->toFloat() < rhs.toFloat() ? true : false;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return this->toFloat() >= rhs.toFloat() ? true : false;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return this->toFloat() <= rhs.toFloat() ? true : false;
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return this->toFloat() == rhs.toFloat() ? true : false;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return this->toFloat() != rhs.toFloat() ? true : false;
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
    return this->toFloat() + rhs.toFloat();
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    return this->toFloat() - rhs.toFloat();
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    return this->toFloat() * rhs.toFloat();
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    return this->toFloat() / rhs.toFloat();
}

Fixed& Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    this->value++;
    return ret;
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    this->value--;
    return ret;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
    return lhs > rhs ? rhs : lhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
    return lhs < rhs ? rhs : lhs;
}

int Fixed::getRawBits() const
{
	return this->value;
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

Fixed::~Fixed()
{
}

float Fixed::toFloat() const
{
    return float(this->value) / (1 << fractional);
}

int Fixed::toInt() const
{
    return this->value >> fractional;
}

std::ostream& operator<<(std::ostream& out, Fixed const& rhs)
{
	out << rhs.toFloat();
	return out;
}