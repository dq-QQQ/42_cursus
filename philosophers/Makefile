# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 23:43:16 by kyujlee           #+#    #+#              #
#    Updated: 2022/04/29 23:43:18 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = Src/philo.c \
	   Src/init.c \
	   Src/philo_func.c \
	   Src/monitoring.c \
	   Src/utils1.c \
	   Src/utils2.c 

SRCS_OBJS = $(SRCS:.c=.o)


.PHONY: all
all : philo

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

philo : $(SRCS_OBJS)
	@$(CC) $(CFLAGS) -o philo $(SRCS_OBJS)
	@echo "complete making execute file"

.PHONY: clean
clean :
	@rm -rf Src/*.o

.PHONY: fclean
fclean : clean
	@rm -rf philo
	@echo "clean object file and execute file"

.PHONY: re
re : fclean all
