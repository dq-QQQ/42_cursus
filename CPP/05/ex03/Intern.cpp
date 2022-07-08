/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:05:42 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 19:33:05 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {if (this == &other) std::cout << "same";}

const Intern& Intern::operator=(const Intern& rhs) 
{
    if (this == &rhs)
        std::cout << "same"; 
    return *this;        
}

Intern::~Intern() {}

Form *Intern::makeForm(const std::string &form, const std::string &target)
{
    Form* ret = NULL;
    std::string name[3] = {"shrubbery creation", "robotomy request", "presidental pardon"};
    int idx = -1;

    for (int i = 0; i < 3; i++)
    {
        if (form == name[i])
        {
            idx= i;
            break;
        }  
    }

    switch(idx) {
        case -1 :
            throw Intern::NoExistFormException();
        case 0 :
            ret = new ShrubberyCreationForm(target);
            break;
        case 1 :
            ret = new RobotomyRequestForm(target);
            break;
        case 2 :
            ret = new PresidentialPardonForm(target);
            break;
    }
    return ret;
}

const char* Intern::NoExistFormException::what() const throw()
{
    return ("There's no exist form");
}
