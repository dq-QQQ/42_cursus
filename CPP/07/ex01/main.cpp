/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:43:59 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 20:58:02 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(const T& v)
{
	std::cout << v << " ";
}

int main()
{
    {//int 예시
        int arr1[5] = {42, 43, 44, 45, 46};
        iter(arr1, 5, print);
    }
    std::cout << "\n\n";
    {//double 예시
        double arr2[5] = {1, 2, 3, 4, 5};
        iter(arr2, 5, print);
    }
    std::cout << "\n\n";
    {//string 예시
        std::string arr3[5] = {"hi", "my", "name","is", "kyujin"};
        iter(arr3, 5, print);
    }
}