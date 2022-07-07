/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:53 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/07 18:22:31 by kyujlee          ###   ########.fr       */
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
        std::cout << e.what() << "\n\n";
    }

    try 
    {
        Bureaucrat b("kyujin", 0);
        Bureaucrat c = b;
        std::cout << c;
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n\n";
    }

    try 
    {
        Bureaucrat b("kyujin", 100);
        Bureaucrat c = b;
        std::cout << c;
        c.gradeDown();
        std::cout << c;
        c.gradeUp();
        std::cout << c;
        
    } 
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n\n";
    }
}