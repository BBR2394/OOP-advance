
CXX		    =	g++
CXXFLAGS	=	-std=c++11

SRC	=	coinminer.cpp			

OBJ	=	$(SRC:.cpp=.o)

NAME	=	coinminer

LFLAGS	=	-L /usr/local/Cellar/openssl@1.1/ -lssl -lcrypto -I/usr/local/Cellar/openssl@1.1/1.1.1d/include

all: $(NAME)

coin: fclean $(NAME)

packages: 
	sudo apt-get install libssl

$(NAME): $(OBJ) $(CFLAGS)
	$(CXX) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
