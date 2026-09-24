/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vananiev <vananiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 11:15:34 by vananiev          #+#    #+#             */
/*   Updated: 2026/08/31 11:53:23 by vananiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_f_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//inits new object
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

//replaces contents 
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &src)
		this->_fp_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}