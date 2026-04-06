#ifndef CONTACT_H
# define CONTACT_H
# include <string>
class Contact
{
private:
	int			index;
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
public:
	Contact(/* args */);
	~Contact();
	std::string Contact::GetFirstName();
	std::string Contact::GetLastName();
	std::string Contact::GetNickName();
	void	Contact::updateFirstName(std::string firstname);
	void	Contact::updateLastName(std::string lastname);
	void	Contact::updateNickName(std::string nickname);
};
#endif