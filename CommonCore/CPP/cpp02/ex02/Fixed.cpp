/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:21:29 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/07 23:34:59 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_rawvalue = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}
Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_rawvalue = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
};
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};
int	Fixed::getRawBits(void) const
{
	return this->_rawvalue;
};
void Fixed::setRawBits(int const raw)
{
	this->_rawvalue = raw;
};
Fixed::Fixed(const int val_int)
{
	this->_rawvalue = val_int << this->_fractional_bit_num;
	std::cout << "Int constructor called" << std::endl;
};
Fixed::Fixed(const float val_float)
{
	this->_rawvalue = roundf(val_float * (1 << this->_fractional_bit_num));
	std::cout << "Float constructor called" << std::endl;
};
float Fixed::toFloat(void) const
{
	return ((float)this->_rawvalue / (1 << this->_fractional_bit_num));
};
int Fixed::toInt(void) const
{
	return (this->_rawvalue >> this->_fractional_bit_num);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_rawvalue > other._rawvalue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_rawvalue < other._rawvalue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_rawvalue >= other._rawvalue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_rawvalue <= other._rawvalue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_rawvalue == other._rawvalue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_rawvalue != other._rawvalue);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_rawvalue + other._rawvalue);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_rawvalue - other._rawvalue);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()      // pre-increment
{
	this->_rawvalue++;
	return *this;
}

Fixed Fixed::operator++(int)    // post-increment
{
	Fixed oldval(*this);
	this->_rawvalue++;
	return oldval;
}

Fixed& Fixed::operator--()      // pre-decrement
{
	this->_rawvalue--;
	return *this;
}

Fixed Fixed::operator--(int)    // post-decrement
{
	Fixed oldval(*this);
	this->_rawvalue--;
	return oldval;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}