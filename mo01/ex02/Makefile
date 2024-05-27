NAME	= ex02

.PHONY : all re fclean

all : $(NAME)

$(NAME) : main.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -o brain main.cpp

re : fclean all

fclean :
	rm -rf brain
