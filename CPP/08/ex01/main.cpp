/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:14:19 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/10 14:32:36 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    try
    {
        unsigned int cap = 1000;
        Span sp(cap);
        std::vector<int> v;
        Span sp2(cap);

        srand(time(NULL));
        for (unsigned int i = 0; i < cap; i++)
        {
            int tmp = rand() % 10000;
            sp.addNumber(tmp);
            v.push_back(tmp);
        }

        sp2.addNumbers(v.begin(), v.end());

        std::cout << "sp short : " << sp.shortestSpan() 
                  << " / sp long : " << sp.longestSpan() << "\n";
        std::cout << "sp2 short : " << sp2.shortestSpan() 
                  << " / sp2 long : " << sp2.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    
    
    return 0;
}