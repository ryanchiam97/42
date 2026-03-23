#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::_addContact(Contact contact)
{
    if (_index < 8)
    {
        _index++;
        _size++;
        _contacts[_index - 1] = contact;
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            _contacts[i] = _contacts[i + 1];
        }
        _contacts[7] = contact;
    }
}

void PhoneBook::_searchContact(int i) const
{
    while (i < 0 || i >= _size)
    {
        std::cout << "Invalid index. Please enter a valid index: ";
        std::cin >> i;
    }
    std::cout << "First Name: " << _contacts[i].getFirstName() << " | ";
    std::cout << "Last Name: " << _contacts[i].getLastName() << " | ";
    std::cout << "Nickname: " << _contacts[i].getNickName() << " | ";
    std::cout << "Darkest Secret: " << _contacts[i].getDarkestSecret() << std::endl;
}
