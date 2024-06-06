NAME	= claptrap

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror
RM			= rm -rf

SRC	= $(wildcard *.cpp)
OBJ	= $(SRC:.cpp=.o)

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
