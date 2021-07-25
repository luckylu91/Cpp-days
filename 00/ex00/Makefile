NAME = megaphone
SRCS = megaphone.cpp

all: $(NAME)

$(NAME):	$(SRCS)
	clang++ $(SRCS) -o $@ -Wall -Wextra -Werror -std=c++98

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all, fclean, re
