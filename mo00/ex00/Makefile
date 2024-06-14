NAME	= megaphone

.PHONY : all re fclean

all : $(NAME)

$(NAME) : megaphone.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) megaphone.cpp

re : fclean all

fclean :
	rm -rf $(NAME) megaphone.o
