/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:30:45 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/07 21:25:46 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->_rawvalue = 0;
	std::cout << "Default Constructor called" << std::endl;
};
Fixed::Fixed(const Fixed& other)
{
	this->_rawvalue = other.getRawBits();
	std::cout << "Copy Constructor called" << std::endl;
};
Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_rawvalue = other.getRawBits();
	std::cout << "Copy Assignment Operator called" << std::endl;
	return *this;
};

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits() called" << std::endl;
	return this->_rawvalue;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawvalue = raw;
	std::cout << "setRawBits() called" << std::endl;
};
Fixed::~Fixed()
{
	std::cout << "Desctructor called" << std::endl;
};
