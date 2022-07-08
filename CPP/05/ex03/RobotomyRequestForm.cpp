/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:39:13 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 18:53:37 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : 
            Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
			Form("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :
			Form("RobotomyRequestForm", 72, 45) ,target(other.getTarget()){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->target = rhs.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const
{
    return this->target;
}

void  RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw Form::NoSignedFormException();
    else if (executor.getGrade() > this->getGradeForEXE())
		throw Form::GradeTooLowException();
    else
    {
        std::cout << "some drilling noises" << std::endl;
        if (rand() % 2)
            std::cout << this->target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->target << " hasn't been robotomized" << std::endl;
    }
}