# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 18:53:48 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/11 18:53:49 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone

.PHONY : all re fclean

all : $(NAME)

$(NAME) : megaphone.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) megaphone.cpp

re : fclean all

fclean :
	rm -rf $(NAME) megaphone.o
