/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:05:21 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/06 00:01:51 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain is created." << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy Brain is created." << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& rhs)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = rhs.getIdeas(i);
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain is deleted." << std::endl;
}

const std::string& Brain::getIdeas(int i) const
{
    return this->ideas[i];
}

void Brain::setIdeas(std::string idea, int i)
{
    this->ideas[i] = idea;
}