
CXX		    =	g++
CXXFLAGS	=	-std=c++11

SRC	=	main.cpp			\
		CheckOption.cpp		\
		Token.cpp			\
		MyMiner.cpp			\
		Time.cpp			\
		Nonce.cpp			\
		OSSLMiner.cpp			\
		FakeMiner.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	coincoin

LFLAGS	=	-L /usr/local/Cellar/openssl@1.1/ -lssl -lcrypto -I/usr/local/Cellar/openssl@1.1/1.1.1d/include

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
