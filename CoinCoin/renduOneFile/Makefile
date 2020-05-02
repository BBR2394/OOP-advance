
CXX		    =	g++
CXXFLAGS	=	-std=c++11

SRC	=	coincoin.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	a.out

LFLAGS	=	 -lssl -lcrypto 

all: $(NAME)

coin: fclean $(NAME)

package: 
	sudo apt-get install libssl

$(NAME): $(OBJ) $(CFLAGS)
	$(CXX) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
