# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 11:35:57 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/12 11:35:59 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= brain

.PHONY : all re fclean

all : $(NAME)

$(NAME) : main.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -o $(NAME) main.cpp

re : fclean all

fclean :
	rm -rf $(NAME)
