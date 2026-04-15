/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:14:42 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/15 23:47:21 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _count(0), _nextIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}
void    PhoneBook::addContact(const Contact& newcontact)
{
    _contacts[_nextIndex] = newcontact;
    _nextIndex = (_nextIndex + 1) % 8;
    if (_count < 8)
        _count++;
}

int    PhoneBook::getCount() const
{
    return (_count);
}

std::string PhoneBook::formatColumn(const std::string& str) const
{
    if (str.length() > 10)
        return (str.substr(0,9) + ".");
    return (str);
}

void    PhoneBook::displaySearchTable() const
{
    int i = 0;
    std::cout << std::right 
                << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << std::endl;
    while (i < _count)
    {
        displaySearchTableRow(i);
        i++;
    }
}

void    PhoneBook::displaySearchResult(int index) const
{
    std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
    std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}
void    PhoneBook::displaySearchTableRow(int index) const
{
    std::cout << std::setw(10) << index << "|"
                << std::setw(10) << formatColumn(_contacts[index].getFirstName()) << "|"
                << std::setw(10) << formatColumn(_contacts[index].getLastName()) << "|"
                << std::setw(10) << formatColumn(_contacts[index].getNickName()) <<std::endl;
}

bool    PhoneBook::validIndex(int index) const
{
    return (index >= 0 && index < _count);
}
