CC =	clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME =	prog
SRCS =	main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
INC = AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
