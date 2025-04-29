NAME	= btc
FILES	= main.cpp BitcoinExchange.cpp BitcoinExchange.hpp

.PHONY : all clean re fclean

all : $(NAME)

$(NAME) : $(FILES)
	c++ -Wall -Wextra -Werror -std=c++98 -g $(FILES) -o $(NAME)

re : fclean all

clean : all

fclean :
	rm -rf $(NAME)
