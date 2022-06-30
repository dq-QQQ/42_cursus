/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:47:21 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/30 20:27:18 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void replace_text(std::string filename, std::string text_in_file, std::string s1, std::string s2)
{
    std::fstream file;
    int index = 0;

    while ((index = text_in_file.find(s1, index)) != -1)
    {
        text_in_file.erase(index, s1.length());
        text_in_file.insert(index, s2);
        index += s2.length();
    }
    file.open(filename + ".replace", std::ios::out);
    file << text_in_file;
    file.close();
}

std::string get_text(const std::string filename)
{
    std::fstream file;
    std::string ret;
    std::string tmp;

    file.open(filename, std::ios::in);
    if (!file)
        return ret;
    while (std::getline(file, tmp))
    {
        ret += tmp;
        if (file.eof())
            break ;
        ret += "\n";
    }
    file.close();
    return ret;
}

int main(int argc, char **argv)
{
    std::string text_in_file;
    std::string filename;
    std::string s1;
    std::string s2;

    if (argc != 4)
    {
        std::cout << "ERR : arg" << std::endl;
        return (0);
    }
    
    filename = argv[1];
    text_in_file = get_text(filename);
    s1 = argv[2];
    s2 = argv[3];
    if (text_in_file.empty())
        return (0);
    
    replace_text(filename, text_in_file, s1, s2);
}