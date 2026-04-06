#ifndef PhoneBook_HPP
# define PhoneBook_HPP
# include "Contact.hpp"
class PhoneBook
{
private:
    Contact contacts[8];
    int     nextIndex;
    int     totalContacts;

public:
    PhoneBook();
    ~PhoneBook();
    void PhoneBook::AddContact(Contact contact);
    void PhoneBook::SearchContact(int index);
};
#endif