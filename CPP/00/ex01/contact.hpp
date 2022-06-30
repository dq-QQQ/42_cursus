/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:05:05 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/29 00:19:05 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact 
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string secret;
public:
    void set_first_name(std::string s);
    void set_last_name(std::string s);
    void set_nickname(std::string s);
    void set_phone(std::string s);
    void set_secret(std::string s);
    std::string get_first_name();
    std::string get_last_name();
    std::string get_nickname();
    std::string get_phone();
    std::string get_secret();
};