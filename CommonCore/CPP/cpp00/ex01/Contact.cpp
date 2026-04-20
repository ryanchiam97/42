/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:14:58 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/15 23:47:06 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(const std::string& newfirstname)
{
    _firstName = newfirstname;
}

void	Contact::setLastName(const std::string& newlastname)
{
    _lastName = newlastname;
}

void	Contact::setNickName(const std::string& newnickname)
{
    _nickName = newnickname;
}
void    Contact::setPhoneNumber(const std::string& phonenumber)
{
    _phoneNumber=phonenumber;
}

void    Contact::setDarkestSecret(const std::string& darkestsecret)
{
    _darkestSecret=darkestsecret;
}


std::string Contact::getFirstName() const
{
    return (_firstName);
}
std::string Contact::getLastName() const
{
    return (_lastName);
}

std::string Contact::getNickName() const
{
    return (_nickName);
}

std::string Contact::getPhoneNumber() const
{
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (_darkestSecret);
}
