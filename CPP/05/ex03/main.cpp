/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:53 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 19:39:19 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    try 
    {
        Bureaucrat b("kyujin", 1);
        Form* rrf;
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("presiden", "Bender");
        rrf->beSigned(b);
        b.executeForm(*rrf);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }
}