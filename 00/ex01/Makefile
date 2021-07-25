NAME = contacts
SRCS = main.cpp Contact.cpp
HEADERS = Contact.hpp

all:	$(NAME)

$(NAME):	$(SRCS) $(HEADERS)
	clang++ $(SRCS) -o $@ -Wall -Wextra -Werror -std=c++98

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all, fclean, re
