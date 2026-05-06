/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:30:33 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/06 23:10:43 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
class Fixed
{
	private:
		int					_value; // raw value in fixed point
		static const int	_fractional_bit_num = 8; // 2 ^ 8 = 256
	public:
		Fixed();//constructor
		Fixed::Fixed(const Fixed& other); // copy constructor
		//constructs new object with same value
		Fixed &Fixed::operator=(const Fixed& other); // copy operator assignment
		// turns to: a = b into a.operator=(b);
		~Fixed();//deconstructor
		int	Fixed::getRawBits(void) const;
		void Fixed::setRawBits(int const raw);
};
#endif