CC =	clang++
CFLAGS = -Wall -Wextra -Werror
NAME =	prog
SRCS =	main.cpp AssaultTerminator.cpp Squad.cpp TacticalMarine.cpp
INC =	AssaultTerminator.hpp ISpaceMarine.hpp ISquad.hpp Squad.hpp TacticalMarine.hpp

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re