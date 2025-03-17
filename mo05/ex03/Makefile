# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 19:32:59 by pepaloma          #+#    #+#              #
#    Updated: 2025/03/17 12:28:36 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= bureaucrat
SRC		:= Bureaucrat.cpp AForm.cpp main.cpp PresidentialPardonForm.cpp \
		ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
		Intern.cpp
OBJ		:= Bureaucrat.o AForm.o main.o PresidentialPardonForm.o \
		Intern.o \
		ShrubberyCreationForm.o RobotomyRequestForm.o

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
