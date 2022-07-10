/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:34:20 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/10 15:02:07 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack &other) { *this = other; }
    MutantStack &operator=(const MutantStack &rhs) { this->c = rhs.c; return *this;}
    ~MutantStack() {}


    typedef typename std::deque<T>::iterator iterator;
    iterator begin() { return this->c.begin(); };
    iterator end() { return this->c.end(); };

    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return this->c.rbegin(); };
    reverse_iterator rend() { return this->c.rend(); };
};