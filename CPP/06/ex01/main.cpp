/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:01:54 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 18:36:56 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct Data
{
    int ex;
    std::string str;
};
uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

int main()
{
    Data d;
    d.ex = 42;
    d.str = "42seoul";

    std::cout << "d's address : " << &d << std::endl << std::endl;

    std::cout << "----------after serialize-----------" << std::endl;
    uintptr_t tmp_int = serialize(&d);
    std::cout <<"value by int : " << tmp_int << std::endl;
    std::cout <<"addr : "<< std::hex << tmp_int << std::endl;
    
    std::cout << "\n----------after deserialize-----------" << std::endl;
    Data *tmp_data = deserialize(tmp_int);
    std::cout << "ex : " << std::dec << tmp_data->ex << " / str : " << tmp_data->str << std::endl;
    std::cout << "addr : " << tmp_data;
}


uintptr_t serialize(Data *ptr)
{
	uintptr_t ret;

	ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data *deserialize(uintptr_t ptr)
{
	Data *ret;

	ret = reinterpret_cast<Data*>(ptr);
	return (ret);
}