
SRCS = Src/pushswap.c 

SRCS_OBJS = $(SRCS:.c=.o)


.PHONY: all
all : push_swap

%.o : %.c
	@gcc -Wall -Wextra -Werror -c $<
	@mv *.o Src

push_swap : $(SRCS_OBJS)
	@gcc -o push_swap $^
	@echo "complete making execute file"

.PHONY: clean
clean :
	@rm -rf Src/*.o

.PHONY: fclean
fclean : clean
	@rm -rf push_swap
	@echo "clean object file and execute file"

.PHONY: re
re : fclean all