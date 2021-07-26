CC =	clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME =	prog
SRCS =	main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
INC = AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp
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
