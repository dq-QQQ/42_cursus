# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 18:12:04 by kyujlee           #+#    #+#              #
#    Updated: 2022/01/12 18:12:08 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Src/solong.c Src/map.c Src/get_next_line.c Src/solong_utils.c Src/move.c

SRCS_OBJS = $(SRCS:.c=.o)


.PHONY: all
all : solong

%.o : %.c
	gcc -c $<
	mv *.o Src

solong : $(SRCS_OBJS)
	gcc -lmlx -framework opengl -framework appkit -o solong $^

.PHONY: clean
clean :
	rm -rf Src/*.o

.PHONY: fclean
fclean : clean
	rm -rf solong

.PHONY: re
re : fclean all
