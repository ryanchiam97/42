/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 23:01:48 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/06 23:30:08 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
class Fixed
{
	private:
		int					_value; // raw value in fixed point
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
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif