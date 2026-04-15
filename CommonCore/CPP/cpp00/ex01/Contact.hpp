/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:14:53 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/15 23:14:54 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <string>
class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
public:
	Contact();
	~Contact();
	void	setFirstName(const std::string& firstname);
	void	setLastName(const std::string& lastname);
	void	setNickName(const std::string& nickname);
	void	setPhoneNumber(const std::string& phonenumber);
	void	setDarkestSecret(const std::string& darkestSecret);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
};
#endif