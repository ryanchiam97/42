/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:14:38 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/15 23:46:39 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

bool	promptInput(const std::string& prompt, std::string& input)
{
	while (true)
	{
		std::cout << prompt << std::flush;
		if (!std::getline(std::cin, input))
			return (false);
		if (!input.empty())
			return (true);
		std::cout << "Field cannot be empty\n";
	}
}

int main()
{
	PhoneBook	phonebook;
	std::string	command;
	while (true)
	{
		std::cout << "Enter command: " << std::flush;
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
		{
			Contact contact;
			std::string input;
			if (promptInput("Enter first Name: ", input))
				contact.setFirstName(input);
			else
				break;
			if (promptInput("Enter last Name: ", input))
				contact.setLastName(input);
			else
				break;
			if (promptInput("Enter nickname: ", input))
				contact.setNickName(input);
			else
				break;
			if (promptInput("Enter phone number: ", input))
				contact.setPhoneNumber(input);
			else
				break;
			if (promptInput("Enter darkest secret: ", input))
				contact.setDarkestSecret(input);
			else
				break;
			phonebook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			if (phonebook.getCount() == 0)
			{
				std::cout << "PhoneBook is empty\n";
				continue;
			}
			std::string indexinput;
			phonebook.displaySearchTable();
			if (promptInput("Enter Contact Index: ", indexinput))
			{
				if (indexinput.length() != 1 || indexinput[0] < '0' || indexinput[0] > '7')
					std::cout << "Invalid index\n";
				else
				{
					int index = indexinput[0]-'0';
					if (!phonebook.validIndex(index))
						std::cout << "Invalid index\n";
					else
						phonebook.displaySearchResult(index);
				}
			}
		}
		else if (command == "EXIT")
		{
			break ;
		}
	}
	return (0);
}