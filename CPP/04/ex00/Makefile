# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 14:45:37 by kyujlee           #+#    #+#              #
#    Updated: 2022/07/06 23:14:02 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX= c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp main.cpp

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