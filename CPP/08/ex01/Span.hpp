/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:42:11 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/10 14:15:38 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>


class Span
{
private:
    std::vector<int> v;
    unsigned int N;
public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& rhs);
    ~Span();

    void addNumber(const int a);

    std::vector<int> getVector() const;
    unsigned int getSize() const;

    int shortestSpan();
	int longestSpan();

    void addNumbers(const std::vector<int>::iterator begin, const std::vector<int>::iterator end);

    class NoSpanFoundException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class FullContainerException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};