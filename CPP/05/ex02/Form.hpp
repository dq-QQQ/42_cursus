/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:19:31 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/08 18:20:57 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int grade_for_sign;
    const int grade_for_exe;
public:
    Form();
    Form(std::string name, int grade_for_sign, int grade_for_exe);
    Form(const Form& other);
    Form& operator=(const Form& rhs);
    ~Form();

    void beSigned(Bureaucrat &b);

    const std::string getName() const;
    bool isSigned() const;
    int getGradeForSign() const;
    int getGradeForEXE() const;

    virtual void execute(const Bureaucrat& executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw(); 
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw(); 
    };
    class NoSignedFormException : public std::exception
    {
    public:
        const char* what() const throw(); 
    };
};
std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif