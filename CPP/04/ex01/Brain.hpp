/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:05:17 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/05 23:21:00 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& rhs);
    ~Brain();

    const std::string& getIdeas(int i) const;
    void setIdeas(std::string idea, int i);
};

#endif