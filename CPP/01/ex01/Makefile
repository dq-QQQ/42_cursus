# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 23:49:43 by kyujlee           #+#    #+#              #
#    Updated: 2022/06/29 01:23:08 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = contact.cpp phonebook.cpp main.cpp

SRCS_OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all : phonebook

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

phonebook : $(SRCS_OBJS)
	@$(CC) $(CFLAGS) -o phonebook $(SRCS_OBJS)
	@echo "complete making execute file"

.PHONY: clean
clean :
	@rm -rf *.o

.PHONY: fclean
fclean : clean
	@rm -rf phonebook
	@echo "clean object file and execute file"

.PHONY: re
re : fclean all