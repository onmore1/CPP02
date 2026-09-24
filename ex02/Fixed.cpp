/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vananiev <vananiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 11:15:34 by vananiev          #+#    #+#             */
/*   Updated: 2026/09/16 11:44:22 by vananiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_f_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): _fp_value(value * (1 << this->_f_bits))
{
	
}

Fixed::Fixed(const float value)
{
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


//inits new object
Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

//replaces contents 
Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if(this != &src)
		this->_fp_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fp_value = raw;
}

std::ostream &operator<<(std::ostream &o, Fixed	const &fixed)
{
	o << fixed.toFloat();
	return (o);
}


//pre
Fixed &Fixed::operator++()
{
	this->_fp_value++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy = *this;
	--this->_fp_value;
	return (copy);
}

//post
Fixed &Fixed::operator--()
{
	this->_fp_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy = *this;
	++this->_fp_value;
	return (copy);
}

//compare
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fp_value > other._fp_value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return(this->_fp_value < other._fp_value);
}

bool Fixed::operator>=(const Fixed &other) const

{
	return(this->_fp_value >= other._fp_value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return(this->_fp_value <= other._fp_value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return(this->_fp_value == other._fp_value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return(this->_fp_value != other._fp_value);
}

// math
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result._fp_value = this->_fp_value + other._fp_value;
	return(result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result._fp_value = this->_fp_value - other._fp_value;
	return(result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result._fp_value = static_cast<int>(
		(static_cast<long long>(this->_fp_value) << this->_f_bits)
		/ other._fp_value);
	return(result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result._fp_value = static_cast<int>(
		(static_cast<long long>(this->_fp_value) * other._fp_value)
		>> this->_f_bits);
	return(result);
}
//min
const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}
//max
const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)	
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}