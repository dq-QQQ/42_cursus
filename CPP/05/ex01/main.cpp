/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:53 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/07 23:36:53 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try 
    {
        Bureaucrat b("kyujin", 100);
        Form f("42seoul", 50, 20);
        f.beSigned(b);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    try 
    {
        Bureaucrat b("kyujin", 100);
        Form f("42seoul", 101, 50);
        f.beSigned(b);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }
}