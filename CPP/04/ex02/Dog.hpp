/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:49:16 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/07 00:48:53 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain* brain;
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& rhs);
    virtual ~Dog();

    virtual void makeSound() const;
    void printIdeas(int i) const;
    void setIdeas(int i, std::string idea);
};

#endif