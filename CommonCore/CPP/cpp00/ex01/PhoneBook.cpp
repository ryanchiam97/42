#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}
void PhoneBook::AddContact(Contact newcontact)
{
    if (this->totalContacts < 8)
    {
        this->nextIndex++;
        this->totalContacts++;
        this->contacts[nextIndex] = newcontact;
    }
    else
    {
        int i = 0;
        while (i < 7)
        {
            this->contacts[i] = this->contacts[i + 1];
            i++;
        }
        this->contacts[7] = newcontact;
    }
}

void PhoneBook::SearchContact(int index)
{
    Contact contact = this->contacts[index];
    std::string fname = contact.GetFirstName();
    std::string lname = contact.GetLastName();
    std::string nname = contact.GetNickName();
    std::cout << std::to_string(index) << " | " << fname << " | " << lname << " | " << nname;
    
}