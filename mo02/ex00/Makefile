NAME	= ex00

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRC	= $(wildcard *.cpp)
OBJ	= $(SRC:.cpp=.o)

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

re : all fclean

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJ)
