/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:53 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 18:21:44 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat b("kyujin", 151);
        Bureaucrat c = b;
        std::cout << c;
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    try 
    {
        Bureaucrat b("kyujin", 0);
        Bureaucrat c = b;
        std::cout << c;
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    try 
    {
        Bureaucrat b("kyujin", 100);
        Bureaucrat a("alice", 1);
        Bureaucrat c = b;
        std::cout << c;
        c.gradeDown();
        std::cout << c;
        c.gradeUp();
        std::cout << c;        
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }
}