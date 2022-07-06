/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:22:27 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/04 22:55:30 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>


class ClapTrap
{
protected:
    std::string name;
    int hp;
    int ep;
    int ad;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& rhs);
    ~ClapTrap();
    
    std::string getName() const;
    int getHp() const;
    int getEp() const;
    int getAd() const;

    void setName(std::string *name);
    void setHp(int *hp);
    void setEp(int *ep);
    void setAd(int *ad);
    
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& rhs);