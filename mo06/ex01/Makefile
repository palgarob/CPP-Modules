# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 20:48:03 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/20 02:00:27 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:= serialization
SRC		:= $(wildcard *.cpp)
OBJ		:= $(SRC:.cpp=.o)

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
	rm -rf $(OBJ) $(wildcard *_shrubbery)
