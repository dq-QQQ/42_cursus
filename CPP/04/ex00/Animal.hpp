/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:56:04 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/05 22:09:15 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& rhs);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;
};

#endif