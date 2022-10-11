# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 16:46:33 by gade-alm          #+#    #+#              #
#    Updated: 2022/08/07 15:54:26 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	 	= server.c

OBJSSERVER  = $(SERVER:.c=.o)

CLIENT		= client.c

OBJSCLIENT  = $(CLIENT:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra 
RM 			= rm -f
RMALL       = $(OBJSSERVER) $(OBJSCLIENT) server client

NAME		= minitalk

$(NAME):	server client

all:		$(NAME)

server: 	server.o
			$(CC) $(CFLAGS) server.o -o server

client: 	client.o
			$(CC) $(CFLAGS) client.o -o client

clean:
		$(RM) $(OBJSSERVER) $(OBJSCLIENT)

fclean:		clean
			$(RM) server client

re:			fclean $(all)

.PHONY:		all clean fclean re 
