/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 23:47:51 by rchiam            #+#    #+#             */
/*   Updated: 2026/05/08 23:22:13 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name): 
	_name(name),
	_hitpt(10),
	_energy(10),
	_atkdmg(0)
{
	std::cout << "Constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->_hitpt = other._hitpt;
	this->_energy = other._energy;
	this->_atkdmg = other._atkdmg;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor Called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitpt == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target \
	<< ", causing " << std::to_string(this->_atkdmg) << " points of damage!" \
	<< std::endl;
	int e = this->_energy;
	e--;
	this->_energy = e;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpt == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " has taken " \
	<< std::to_string(amount) << " damage!" << std::endl;
	int h = this->_hitpt;
	h--;
	this->_hitpt = h;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpt == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points" << std::endl;
		return ;
	}
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is being repaired by " \
	<< std::to_string(amount) << " Hit points!" << std::endl;
	int h = this->_hitpt;
	h++;
	this->_hitpt = h;
	int e = this->_energy;
	e--;
	this->_energy = e;
}
