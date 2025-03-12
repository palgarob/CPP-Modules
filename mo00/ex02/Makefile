# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:51:57 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/12 11:19:02 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= testAccount

OBJ_DIR	= obj
BIN_DIR	= bin
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC	= $(wildcard *.cpp)
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

.PHONY : all re clean fclean

all : $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME) : $(OBJ) | $(BIN_DIR)
	$(CXX) $(OBJ) -o $@

$(BIN_DIR) :
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o : %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

re : fclean all

fclean : clean
	$(RM) $(BIN_DIR)

clean :
	$(RM) $(OBJ_DIR)
