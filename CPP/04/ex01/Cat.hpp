/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:57:56 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/07 00:49:01 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* brain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& rhs);
    virtual ~Cat();

    virtual void makeSound() const;
    void printIdeas(int i) const;
    void setIdeas(int i, std::string idea);
};

#endif