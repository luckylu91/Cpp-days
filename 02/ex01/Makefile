CC =	clang++
CFLAGS = -Wall -Wextra -Werror
NAME =	prog
SRCS =	main.cpp Fixed.cpp
INC =	Fixed.hpp

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re