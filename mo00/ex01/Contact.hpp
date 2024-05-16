#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

class Contact {

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;

	public:
		Contact(void);
		~Contact(void);

		void	init(void);
		void	contact_info(void);

};

#endif
