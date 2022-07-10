/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:53:21 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/10 14:31:23 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {};

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& other) { *this = other; }

Span& Span::operator=(const Span& rhs)
{
    this->v = rhs.getVector();
    this->N = rhs.getSize();
    return *this;
}

Span::~Span() {}

void Span::addNumber(const int a) 
{
    if (v.size() == N)
        throw Span::FullContainerException(); 
    v.push_back(a); 
}

std::vector<int> Span::getVector() const { return this->v; }

unsigned int Span::getSize() const { return this->N; }

int Span::shortestSpan()
{
    if (v.size() < 2)
        throw Span::NoSpanFoundException();
    int ret = std::abs(v[1] - v[0]);
    for (unsigned int i = 1; i < v.size() - 1; i++)
        ret = std::min(ret, std::abs(v[i + 1] - v[i]));
    return ret;
}

int Span::longestSpan()
{
    if (v.size() < 2)
        throw Span::NoSpanFoundException();
    int min = *std::min_element(v.begin(), v.end());
    int max = *std::max_element(v.begin(), v.end());
    return (max - min);
}

void Span::addNumbers(const std::vector<int>::iterator begin, const std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it != end; it++)
    {
       if (v.size() == N)
            throw Span::FullContainerException(); 
        v.push_back(*it);
    }
}

const char* Span::FullContainerException::what() const throw()
{
    return "CONTAINER IS FULLED";
}

const char* Span::NoSpanFoundException::what() const throw()
{
    return "ELEMENT IS TOO FEW TO CALCULATE";
}