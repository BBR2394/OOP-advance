
CXX		    =	g++
CXXFLAGS	=	-std=c++11

SRC	=	coinminer.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	coinminer

LFLAGS	=	 -lssl -lcrypto 

all: $(NAME)

coin: fclean $(NAME)

packages: 
	sudo apt-get install libssl-dev

$(NAME): $(OBJ) $(CFLAGS)
	$(CXX) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
