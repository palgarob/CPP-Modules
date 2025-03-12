# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 20:18:40 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/12 20:18:41 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fixed

OBJ_DIR	= obj

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC	= $(wildcard *.cpp)
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

re : fclean all

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ_DIR)
