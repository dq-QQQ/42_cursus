/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:59:11 by kyujlee           #+#    #+#             */
/*   Updated: 2022/07/09 22:21:54 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array
{
private:
    T *arr;
    int m_size;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array& operator=(const Array &rhs);
    ~Array();

    T& operator[](const int& i) const;

    int size() const;
    class OutOfBoundsException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

template <typename T>
Array<T>::Array() : arr(new T[0]), m_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), m_size(n) {}

template <typename T>
Array<T>::Array(const Array& other) { *this = other; }


template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    if (this->arr)
        delete[] this->arr;
    arr =  new T[rhs.size()];
    m_size = rhs.size();
    for (int i = 0; i < m_size; i++)
        arr[i] = rhs.arr[i];
    return *this;
}


template <typename T>
Array<T>::~Array()
{
	if (arr)
		delete[] this->arr;
}

template <typename T>
T& Array<T>::operator[](const int& i) const
{
    if (i < 0 || i >= m_size)
        throw Array<T>::OutOfBoundsException();
    return arr[i];
}

template <typename T>
int Array<T>::size(void) const { return (this->m_size); }

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("out of bounds");
}