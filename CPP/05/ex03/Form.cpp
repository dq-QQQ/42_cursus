/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:25:01 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 00:07:31 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("") , is_signed(false), grade_for_sign(150), grade_for_exe(150) {}

Form::Form(std::string name, int grade_for_sign, int grade_for_exe) : name(name)
, is_signed(false), grade_for_sign(grade_for_sign), grade_for_exe(grade_for_exe)
{
    if (grade_for_sign < 0 || grade_for_exe < 0)
		throw Form::GradeTooHighException();
	else if (grade_for_sign > 150 || grade_for_exe > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : name(other.getName())
, is_signed(other.isSigned()), grade_for_sign(other.getGradeForSign())
, grade_for_exe(other.getGradeForEXE())
{
    
}

Form& Form::operator=(const Form& rhs)
{
    this->is_signed = rhs.isSigned();
    return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= grade_for_sign)
		this->is_signed = true;

	b.signForm(this->isSigned(), this->getName());
	
    if (b.getGrade() > grade_for_sign)
		throw Form::GradeTooLowException();
}

const std::string Form::getName() const
{
    return this->name;
}

bool Form::isSigned() const
{
    return this->is_signed;
}

int Form::getGradeForSign() const
{
    return this->grade_for_sign;
}

int Form::getGradeForEXE() const
{
    return this->grade_for_exe;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char *Form::NoSignedFormException::what() const throw()
{
	return ("This form isn't signed yet");
}