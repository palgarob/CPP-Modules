# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:51:57 by pepaloma          #+#    #+#              #
#    Updated: 2024/05/27 11:58:50 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC	= $(wildcard *.cpp)
OBJ	= $(SRC:.cpp=.o)

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

re : fclean all

fclean : clean
	$(RM) phonebook

clean :
	$(RM) $(OBJ)
