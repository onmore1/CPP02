/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vananiev <vananiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 11:15:34 by vananiev          #+#    #+#             */
/*   Updated: 2026/09/16 12:55:55 by vananiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_f_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): _fp_value(value * (1 << this->_f_bits))
{
	std::cout << "Int constructor called" << "\n";
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << "\n";
	this->_fp_value = static_cast<int>(roundf(value * (1 << this->_f_bits)));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fp_value) / (1 << this->_f_bits); // 2^8
}

int Fixed::toInt() const
{
	return this->_fp_value >> this->_f_bits;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &src)
		this->_fp_value = src._fp_value;
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

std::ostream &operator<<(std::ostream &o, Fixed	const &fixed)
{
	o << fixed.toFloat();
	return (o);
}