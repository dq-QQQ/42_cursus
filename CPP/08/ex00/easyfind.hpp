/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:35:10 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/10 12:34:01 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

class NoMatchValueException : public std::exception
{
public:
    const char* what() const throw();
};

template <typename T>
typename T::iterator easyFind(T& container, const int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
		throw NoMatchValueException();
	return it;
}
