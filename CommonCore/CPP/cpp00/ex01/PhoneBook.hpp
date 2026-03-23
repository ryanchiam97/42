#ifndef PhoneBook_HPP
# define PhoneBook_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _index;
		int _size;

	
	public:
		PhoneBook();
		~PhoneBook();
		void _addContact(Contact contact);
		void _searchContact(int i) const;
};

#endif