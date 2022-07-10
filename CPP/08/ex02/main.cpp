/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:34:16 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/10 18:57:44 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl<< std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

// #include <list>

// int main()
// {
//     MutantStack<int> ms;
//     std::list<int>	list;

//     ms.push(42);
//     list.push_back(42);

//     ms.push(43);
//     list.push_back(43);

//     ms.push(44);
//     list.push_back(44);


//     std::list<int>::iterator l_it = list.begin();
//     std::list<int>::iterator l_ite = list.end();

//     MutantStack<int>::iterator ms_it = ms.begin();
//     MutantStack<int>::iterator ms_ite = ms.end();

//     while (l_it != l_ite)
//     {
//         std::cout << *l_it << std::endl;
//         ++l_it;
//     }
//     std::cout << std::endl;
//     while (ms_it != ms_ite)
//     {
//         std::cout << *ms_it << std::endl;
//         ++ms_it;
//     }
// }