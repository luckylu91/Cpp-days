CC =	clang++
CFLAGS = -Wall -Wextra -Werror
NAME =	replace
SRCS =	main.cpp

all:	$(NAME)

$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re