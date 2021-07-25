CC =	clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME =	replace
SRCS =	main.cpp

all:	$(NAME)

$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
