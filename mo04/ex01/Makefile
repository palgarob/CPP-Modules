# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 20:59:22 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/12 20:59:23 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= animal

OBJ_DIR	= obj

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror
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

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all
