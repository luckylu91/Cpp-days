CC =	clang++
CFLAGS = -Wall -Wextra -Werror
NAME =	convert
SRCS =	main.cpp
INC =

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
