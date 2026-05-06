/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:30:45 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/06 22:51:27 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default Constructor called" << std::endl;
};
Fixed::Fixed(const Fixed& other)
{
	this->_value = other.getRawBits();
	std::cout << "Copy Constructor called" << std::endl;
};
Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	std::cout << "Copy Assignment Operator called" << std::endl;
	return *this;
};

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits() called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	std::cout << "setRawBits() called" << std::endl;
};
Fixed::~Fixed()
{
	std::cout << "Desctructor called" << std::endl;
};
