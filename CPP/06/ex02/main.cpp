/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:47:52 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 21:08:15 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base * generate(void)
{
    Base* ret;

    srand(time(NULL));
    switch (rand() % 3){
        case 0: 
            ret = new A;
            break;
        case 1: 
            ret = new B;
            break;
        case 2: 
            ret = new C;
            break;
    }

    return ret;
}

void identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
    if (a)
		std::cout << "A class ptr" << std::endl;
	if (b)
		std::cout << "B class ptr" << std::endl;
	if (c)
		std::cout << "C class ptr" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "A class ref" << std::endl;
    }
    catch(const std::exception& e){}

    try
    {
        B b = dynamic_cast<B&>(p);
        std::cout << "B class ref" << std::endl;
    }
    catch(const std::exception& e){}

    try
    {
        C c = dynamic_cast<C&>(p);
        std::cout << "C class ref" << std::endl;
    }
    catch(const std::exception& e){}
    
}

int main()
{
    Base *b;

    b = generate();
    identify(b);
    identify(*b);
}