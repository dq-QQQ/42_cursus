# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 14:05:20 by kyujlee           #+#    #+#              #
#    Updated: 2021/05/14 11:23:20 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strchr.c ft_strrchr.c \
	   ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
	   ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BOBJS = $(BSRCS:.c=.o)

NAME = libft.a

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BOBJS)
else
	OBJ_FILES = $(OBJS)
endif

.PHONY: all
all : $(NAME)

%.o : %.c
	gcc -Wall -Wextra -Werror -c -o $@ $<

$(NAME) : $(OBJ_FILES)
	ar cr $@ $^

.PHONY: bonus
bonus :
	make WITH_BONUS=1 all

.PHONY: clean
clean :
	rm -f $(OBJS) $(BOBJS)

.PHONY: fclean
fclean : clean
	rm -f $(NAME)

.PHONY: re
re : fclean all
