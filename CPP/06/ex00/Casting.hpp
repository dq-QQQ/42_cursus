/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Casting.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:16:34 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 17:51:40 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

class Casting 
{
private:
    double value;
public:
    Casting();
    Casting(char* str);
    Casting(const Casting& other);
    Casting& operator=(const Casting& rhs);
    ~Casting();

    double getValue() const;

    void printChar() const;
    void printInt() const;
    void printFloat() const;
    void printDouble() const;
};