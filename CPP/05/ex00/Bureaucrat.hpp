/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:37:39 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/07 18:41:27 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <exception>

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& rhs);
    ~Bureaucrat();

    const std::string getName() const;
    int getGrade() const;
    void gradeUp();
	void gradeDown();

    void signForm(bool is_signed, std::string form_name);

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
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);
