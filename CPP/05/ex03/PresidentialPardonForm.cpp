/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:50:06 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 18:54:11 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : 
            Form("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
			Form("PresidentialPardonForm", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) :
			Form("PresidentialPardonForm", 25, 5) ,target(other.getTarget()){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->target = rhs.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string& PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void  PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw Form::NoSignedFormException();
    else if (executor.getGrade() > this->getGradeForEXE())
		throw Form::GradeTooLowException();
    else
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}