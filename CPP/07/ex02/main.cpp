/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:08:25 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 22:56:54 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& rhs)
{
    for (int i = 0 ; i < rhs.size(); i++)
        out << rhs[i] << " ";
    out << std::endl;
    return out;
}

// int main()
// {
//     {
//         Array<int> a;
//         Array<int> b(5);

//         for (int i = 0; i < 5; i++)
//             b[i] = 42 + i;
//         std::cout << "b arr : " << b;
//         std::cout << "a arr : " << a;
//         a = b;
//         std::cout << "a arr : " << a;
//     }
//     std::cout << std::endl;
//     {
//         Array<std::string> a(5);
//         a[0] = "hi";
//         a[1] = "my";
//         a[2] = "name";
//         a[3] = "is";
//         a[4] = "kyujin";
//         std::cout << "a arr : " << a;
//         Array<std::string> b(a);
//         std::cout << "b arr : " << b;
//     }
//     std::cout << std::endl;
//     try 
// 	{
//         Array<int> e_a(5);
// 		std::cout << e_a[5] << "ho" << std::endl;
// 	}
// 	catch(std::exception &e) 
//     {
// 		std::cout << e.what() << std::endl;
// 	}
//     std::cout << std::endl;
// 	try 
//     {
//         Array<int> e_b(5);
// 		std::cout << e_b[-1] << "ho2" << std::endl;
// 	}
// 	catch(std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// }

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
