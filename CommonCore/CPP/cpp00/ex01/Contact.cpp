#include "Contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

std::string Contact::GetFirstName()
{
    return this->firstname;
}
std::string Contact::GetLastName()
{
    return this->lastname;
}

std::string Contact::GetNickName()
{
    return this->nickname;
}

void	Contact::updateFirstName(std::string newfirstname)
{
    this->firstname = newfirstname;
}

void	Contact::updateLastName(std::string newlastname)
{
    this->lastname = newlastname;
}

void	Contact::updateNickName(std::string newnickname)
{
    this->nickname = newnickname;
}
