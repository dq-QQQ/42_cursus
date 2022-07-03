# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 16:04:34 by kyujlee           #+#    #+#              #
#    Updated: 2022/07/03 16:04:50 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Harl.cpp main.cpp

SRCS_OBJS = $(SRCS:.cpp=.o)

NAME = file_replace

.PHONY: all
all : $(NAME)

%.o : %.c
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(SRCS_OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS_OBJS)
	@echo "complete making execute file"

.PHONY: clean
clean :
	@rm -rf *.o

.PHONY: fclean
fclean : clean
	@rm -rf $(NAME)
	@echo "clean object file and execute file"

.PHONY: re
re : fclean all