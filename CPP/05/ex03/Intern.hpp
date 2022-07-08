/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:59:38 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 19:27:45 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
public:
    Intern();
    Intern(const Intern& other);
    const Intern& operator=(const Intern& rhs);
    ~Intern();

    Form *makeForm(const std::string &form, const std::string &target);
    
    class NoExistFormException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

#endif