# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 16:54:32 by kyujlee           #+#    #+#              #
#    Updated: 2021/09/22 16:59:22 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_utils.c print_char.c ft_utils2.c print_num.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

.PHONY: all
all : $(NAME)

%.o : %.c
	gcc -Wall -Wextra -Werror -c -o $@ $<

$(NAME) : $(OBJS)
	ar cr $@ $^

.PHONY: clean
clean :
	rm -f $(OBJS) 

.PHONY: fclean
fclean : clean
	rm -f $(NAME)

.PHONY: re
re : fclean all
