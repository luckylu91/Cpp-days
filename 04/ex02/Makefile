CC =	clang++
CFLAGS = -Wall -Wextra -Werror
NAME =	prog
SRCS =	main.cpp Squad.cpp TacticalMarine.cpp AssaultTerminator.cpp
INC = Squad.hpp TacticalMarine.hpp AssaultTerminator.hpp ISpaceMarine.hpp ISquad.hpp

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
