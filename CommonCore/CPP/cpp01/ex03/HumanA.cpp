/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:52:14 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/20 16:37:30 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
    if (this->_weapon.getType().empty()==false)
        std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon to attack with" << std::endl;
}
