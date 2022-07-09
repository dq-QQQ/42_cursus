/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:34:27 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 20:46:20 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(const T& a, const T& b) 
{ 
    if (a < b)
        return a;
    else 
        return b;
}

template <typename T>
T max(const T& a, const T& b) 
{ 
    if (a <= b)
        return b;
    else 
        return a;
}