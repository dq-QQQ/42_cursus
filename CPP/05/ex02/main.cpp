/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:53 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 00:20:45 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try 
    {
        Bureaucrat b("kyujin", 100);
        ShrubberyCreationForm ft("42seoul");
        ft.beSigned(b);
        ft.execute(b);
    } 
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }
}