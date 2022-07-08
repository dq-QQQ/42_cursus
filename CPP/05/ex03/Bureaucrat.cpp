/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:52:35 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 18:21:27 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.getName())
{
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    std::cout << "name must constant" << std::endl;
    this->grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(){}

const std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::gradeUp()
{
    this->grade--;
    if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::gradeDown()
{
    this->grade++;
    if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(bool is_signed, std::string form_name)
{
    if (is_signed)
		std::cout << this->getName() << " signed " << form_name << std::endl;
	else
		std::cout << this->getName() << " couldn’t sign " << form_name << " because ";
}


void Bureaucrat::executeForm(const Form& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName()<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << this->name << " couldn’t executed " << form.getName() << " because " << e.what() << std::endl;
	}
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return out;
}