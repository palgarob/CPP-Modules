# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 19:32:59 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/15 11:21:04 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= bureaucrat
SRC		:= Bureaucrat.cpp Form.cpp main.cpp
OBJ		:= Bureaucrat.o Form.o main.o

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
