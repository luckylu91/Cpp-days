CC =	clang++
CFLAGS = -Wall -Wextra -Werror
NAME =	prog
SRCS =	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
INC =	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
