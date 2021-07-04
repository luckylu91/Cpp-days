CC =	clang++
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow
NAME =	prog
SRCS =	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
INC =	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
