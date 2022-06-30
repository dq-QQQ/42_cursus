/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:43:11 by kyujlee           #+#    #+#             */
/*   Updated: 2022/06/28 23:44:22 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

int main(int argc, char **argv)
{
    int j;

    if (argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            j = -1;
            while (argv[i][++j])
                std::cout << (char)toupper(argv[i][j]);
        }
        std::cout << std::endl;
    }
    return 0;
}