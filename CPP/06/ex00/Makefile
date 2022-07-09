# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 14:45:37 by kyujlee           #+#    #+#              #
#    Updated: 2022/07/09 17:16:25 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Casting.cpp main.cpp

SRCS_OBJS = $(SRCS:.cpp=.o)

NAME = a.out

.PHONY: all
all : $(NAME)

%.o : %.cpp
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