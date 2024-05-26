#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

	private:
		Contact	_contacts[8];
		int		next_entry;
		int		n_contacts;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);

};

#endif
