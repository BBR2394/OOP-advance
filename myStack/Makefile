
CXX		    =	g++
CXXFLAGS	=	

SRC	=	my_main.cpp			\
		mychainedstack.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	mycs-test

all: $(NAME)

$(NAME): $(OBJ) $(CXXFLAGS)
	$(CXX) -o $(NAME) $(OBJ) 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
