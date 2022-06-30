# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 22:39:12 by kyujlee           #+#    #+#              #
#    Updated: 2022/06/30 14:50:16 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

SRCS_OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all : megaphone

%.o : %.c
	@$(CXX) $(CXXFLAGS) -c $< -o $@

megaphone : $(SRCS_OBJS)
	@$(CXX) $(CXXFLAGS) -o megaphone $(SRCS_OBJS)
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