# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 19:32:59 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/13 19:41:06 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= bureaucrat
SRC		:= Bureaucrat.cpp
OBJ		:= Bureaucrat.o main.o

.PHONY : all re clean fclean 

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(OBJ) -o $@

%.o : %.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

re : fclean all

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ)
