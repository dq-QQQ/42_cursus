/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:37:17 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/04 10:18:15 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int fractional;
public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& rhs);
    ~Fixed();

    int getRawBits() const;
	void setRawBits(const int raw);
    float toFloat() const;
    int toInt() const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& rhs);