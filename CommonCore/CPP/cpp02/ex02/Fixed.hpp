/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:21:48 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/07 22:09:36 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <cmath>
# include <iostream>
class Fixed
{
	private:
		int					_rawvalue; // raw value in fixed point
		static const int	_fractional_bit_num = 8; // 2 ^ 8 = 256
	public:
		Fixed();
		Fixed::Fixed(const Fixed& other);
		Fixed &Fixed::operator=(const Fixed& other);
		~Fixed();
		int	Fixed::getRawBits(void) const;
		void Fixed::setRawBits(int const raw);
		Fixed(int val_int);
		Fixed(float val_float);
		float Fixed::toFloat(void) const;
		int Fixed::toInt(void) const;

		bool Fixed::operator>(const Fixed& other) const;
		bool Fixed::operator<(const Fixed& other) const;
		bool Fixed::operator>=(const Fixed& other) const;
		bool Fixed::operator<=(const Fixed& other) const;
		bool Fixed::operator==(const Fixed& other) const;
		bool Fixed::operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();      // pre-increment
		Fixed operator++(int);    // post-increment
		Fixed& operator--();      // pre-decrement
		Fixed operator--(int);    // post-decrement

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif