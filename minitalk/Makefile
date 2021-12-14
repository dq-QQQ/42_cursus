# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 17:20:13 by kyujlee           #+#    #+#              #
#    Updated: 2021/12/14 19:04:15 by kyujlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS = server.c server_utils.c

CLIENT_SRCS = client.c client_utils.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER = server

CLIENT = client

.PHONY: all
all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
	gcc -Wall -Wextra -Werror -o $(SERVER) $(SERVER_SRCS)

$(CLIENT) : $(CLIENT_OBJS)
	gcc -Wall -Wextra -Werror -o $(CLIENT) $(CLIENT_OBJS) 

.PHONY: clean
clean :
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

.PHONY: fclean
fclean : clean
	rm -rf $(SERVER) $(CLIENT) 

.PHONY: re
re : fclean all
