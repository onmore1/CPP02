/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vananiev <vananiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 10:53:16 by vananiev          #+#    #+#             */
/*   Updated: 2026/09/16 11:44:17 by vananiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int 				_fp_value;
		static const int	_f_bits;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed	&operator=(const Fixed &src);
		//comapre
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		// pre
		Fixed &operator++();
		Fixed &operator--();
		// post
		Fixed operator++(int);
		Fixed operator--(int);
		//math
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		//
		float	toFloat(void)const;
		int		toInt(void) const;
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		//max/min
		static	Fixed &min(Fixed &first, Fixed &second);
		static	const Fixed &min(const Fixed &first, const Fixed &second);
		static	Fixed &max(Fixed &first, Fixed &second);
		static	const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif