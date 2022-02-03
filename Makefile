# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaffron <ksaffron@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 14:12:56 by ksaffron          #+#    #+#              #
#    Updated: 2022/01/28 12:24:02 by ksaffron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =

CLIENT_FILES = utils.c client.c ft_atoi.c
SERVER_FILES = server.c utils.c ft_atoi.c

CLIENT_FILES_BONUS = client_bonus.c utils_bonus.c ft_atoi.c
SERVER_FILES_BONUS = server_bonus.c utils_bonus.c ft_atoi.c

OBJ_CLIENT = $(patsubst %.c, %.o, $(CLIENT_FILES))
OBJ_SERVER = $(patsubst %.c, %.o, $(SERVER_FILES))

OBJ_CLIENT_BONUS = $(patsubst %.c, %.o, $(CLIENT_FILES_BONUS))
OBJ_SERVER_BONUS = $(patsubst %.c, %.o, $(SERVER_FILES_BONUS))

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER   = server
CLIENT   = client

CC	     = cc
FLAGS    = -Wall -Werror -Wextra
HEADER   = ./header/minitalk.h
HEADER_BONUS   = ./header/minitalk_bonus.h

all : $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER) : $(HEADER) $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) -o $@

$(CLIENT) : $(HEADER) $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) -o $@

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

bonus:  server_bonus client_bonus

$(CLIENT_BONUS) : $(HEADER_BONUS) $(OBJ_CLIENT_BONUS)
	$(CC) $(OBJ_CLIENT_BONUS) -o $@

$(SERVER_BONUS) : $(HEADER_BONUS) $(OBJ_SERVER_BONUS)
	$(CC) $(OBJ_SERVER_BONUS) -o $@

clean :
	rm -f *.o

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: clean fclean all bonus
