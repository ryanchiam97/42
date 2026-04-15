/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiam <rchiam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 23:14:48 by rchiam            #+#    #+#             */
/*   Updated: 2026/04/15 23:40:15 by rchiam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP
# include <string>
# include "Contact.hpp"
class PhoneBook
{
private:
    Contact _contacts[8];
    int     _count;
    int     _nextIndex;

public:
    PhoneBook();
    ~PhoneBook();
    void        addContact(const Contact& contact);
    void        displaySearchTable() const;
    int         getCount() const;
    std::string formatColumn(const std::string& str) const;
    void        displaySearchResult(int index) const;
    void        displaySearchTableRow(int index) const;
    bool        validIndex(int index) const;
};
#endif