CC =	clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME =	prog
SRCS =	main.cpp Base.cpp
INC = A.hpp B.hpp Base.hpp C.hpp

all:	$(NAME)

$(NAME):	$(INC)
$(NAME):	$(SRCS)
	$(CC) -o $@ $(SRCS) $(CFLAGS)

fclean:
	rm $(NAME)

re: fclean all

.PHONY: all fclean re
