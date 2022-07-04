/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:37:17 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/04 09:56:32 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
    int value;
    static const int fractional;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& rhs);
    ~Fixed();

    int getRawBits() const;
	void setRawBits(const int raw);
};