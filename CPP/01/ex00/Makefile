# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 22:39:12 by kyujlee           #+#    #+#              #
#    Updated: 2022/06/28 23:45:32 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

SRCS_OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all : megaphone

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

megaphone : $(SRCS_OBJS)
	@$(CC) $(CFLAGS) -o megaphone $(SRCS_OBJS)
	@echo "complete making execute file"

.PHONY: clean
clean :
	@rm -rf *.o

.PHONY: fclean
fclean : clean
	@rm -rf megaphone
	@echo "clean object file and execute file"

.PHONY: re
re : fclean all