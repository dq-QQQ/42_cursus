/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:47:30 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 00:21:39 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
            Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
			Form("ShrubberyCreationForm", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :
			Form("ShrubberyCreationForm", 145, 137) ,target(other.getTarget()){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	this->target = rhs.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

void  ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw Form::NoSignedFormException();
    else if (executor.getGrade() > this->getGradeForEXE())
		throw Form::GradeTooLowException();
    else
    {
        std::string ascii_tree = "               ,@@@@@@@,\n"
							"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
							"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
							"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
							"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
							"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
							"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
							"       |o|        | |         | |\n"
							"       |.|        | |         | |\n"
							"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";;
		std::ofstream file(this->target + "_shruberry");
		file << ascii_tree;
		std::cout << this->getName() << " was executed" << std::endl;
		file.close();
    }

}