# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 18:12:04 by kyujlee           #+#    #+#              #
#    Updated: 2022/01/15 12:58:34 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = Src/solong.c Src/map.c Src/get_next_line.c Src/solong_utils.c Src/move.c

SRCS_OBJS = $(SRCS:.c=.o)


.PHONY: all
all : so_long

%.o : %.c
	gcc -Wall -Wextra -Werror -c $<
	mv *.o Src

so_long : $(SRCS_OBJS)
	gcc -lmlx -framework opengl -framework appkit -o so_long $^

.PHONY: clean
clean :
	rm -rf Src/*.o

.PHONY: fclean
fclean : clean
	rm -rf solong

.PHONY: re
re : fclean all
