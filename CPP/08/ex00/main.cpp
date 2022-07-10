/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:23:47 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/10 12:38:30 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

const char* NoMatchValueException::what() const throw()
{
    return "No Match Value";
}


int main()
{
    try
    {
        std::vector<int> v;
        std::vector<int>::iterator it;

        v.push_back(42);
        v.push_back(43);
        v.push_back(44);
        v.push_back(45);

        it = easyFind(v, 44);
        std::cout << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    try
    {
        std::vector<int> v;
        std::vector<int>::iterator it;

        v.push_back(0);
        
        it = easyFind(v, 1);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}