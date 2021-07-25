CC =	clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME =	prog
SRCS =	main.cpp Fixed.cpp
INC =	Fixed.hpp

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

.PHONY: all fclean
