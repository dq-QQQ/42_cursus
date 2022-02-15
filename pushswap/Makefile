# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 17:50:52 by kyujlee           #+#    #+#              #
#    Updated: 2022/02/15 18:24:59 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude -fsanitize=address

SRCS = Src/pushswap.c Src/pushswap_utils/ps_utils.c Src/pushswap_utils/ps_utils2.c  Src/pushswap_utils/ps_init_stack.c Src/pushswap_utils/ps_check_inst.c Src/libft_utils/libft_utils.c Src/libft_utils/libft_utils2.c Src/libft_utils/libft_utils3.c Src/operate_utils/ps_operation.c Src/operate_utils/stack_operation.c Src/operate_utils/stack_operation2.c 

SRCS_OBJS = $(SRCS:.c=.o)


.PHONY: all
all : push_swap

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

push_swap : $(SRCS_OBJS)
	@$(CC) $(CFLAGS) -o push_swap $(SRCS_OBJS)
	@echo "complete making execute file"

.PHONY: clean
clean :
	@rm -rf Src/*.o Src/libft_utils/*o Src/operate_utils/*.o Src/pushswap_utils/*.o

.PHONY: fclean
fclean : clean
	@rm -rf push_swap
	@echo "clean object file and execute file"

.PHONY: re
re : fclean all
