NAME = prog
SRCS = tests.cpp Account.cpp
HEADERS = Account.hpp

all:	$(NAME)

$(NAME):	$(SRCS) $(HEADERS)
	clang++ $(SRCS) -o $@ -Wall -Wextra -Werror

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all, fclean, re
