SRCS = Src/solong.c 

SRCS_OBJS = $(SRCS:.c=.o)


.PHONY: all
all : solong

solong : $(SRCS)
	gcc -lmlx -framework opengl -framework appkit -o solong $<

.PHONY: clean
clean :
	rm -rf *.o

.PHONY: fclean
fclean : clean
	rm -rf solong

.PHONY: re
re : fclean all