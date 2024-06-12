NAME	= brain

.PHONY : all re fclean

all : $(NAME)

$(NAME) : main.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) main.cpp

re : fclean all

fclean :
	rm -rf $(NAME)
