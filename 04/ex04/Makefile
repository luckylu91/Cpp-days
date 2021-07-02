CC =	clang++
CFLAGS = -Wall -Wextra -Werror
NAME =	prog
SRCS =	main.cpp DeepCoreMiner.cpp StripMiner.cpp AsteroKreog.cpp KoalaSteroid.cpp MiningBarge.cpp main.cpp
INC = DeepCoreMiner.hpp StripMiner.hpp AsteroKreog.hpp KoalaSteroid.hpp KoalaSteroid.cpp MiningBarge.hpp IAsteroid.hpp IMiningLaser.hpp
OBJS = $(SRCS:.cpp=.o)

all:	$(NAME)

%.o: %.cpp $(INC)
	$(CC) -c $< -o $@ $(CFLAGS)

$(NAME):	$(INC)
$(NAME):	$(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
