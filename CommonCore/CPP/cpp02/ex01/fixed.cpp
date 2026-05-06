/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 23:01:39 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/06 23:31:35 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed()
{
	//
}
Fixed::Fixed(const Fixed& other)
{
	//
}
Fixed &Fixed::operator=(const Fixed& other)
{
	//
}
~Fixed();
int	Fixed::getRawBits(void) const;
void Fixed::setRawBits(int const raw);
Fixed(int val_int);
Fixed(float val_float);
float Fixed::toFloat(void) const;
int Fixed::toInt(void) const;

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}