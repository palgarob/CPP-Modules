NAME	= PmergeMe
FILES	= main.cpp PmergeMe.cpp PmergeMe.hpp

.PHONY : all clean re fclean

all : $(NAME)

$(NAME) : $(FILES)
	c++ -Wall -Wextra -Werror -std=c++98 -g $(FILES) -o $(NAME)

re : fclean all

clean : all

fclean :
	rm -rf $(NAME)
