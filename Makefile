# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chkala-l <chkala-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 17:38:43 by chkala-l          #+#    #+#              #
#    Updated: 2023/09/12 17:59:16 by chkala-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_c = client 
NAME_s = server

CC = cc

CFLAGS += -Wall -Werror -Wextra

RM = rm -f

SRC = client.c \
	  server.c


Obj = $(SRC:.c=.o)


# $(NAME): $(Obj)
# 	ar rcs $(NAME) $(Obj)
client : client.c
		$(CC) $(CFLAGS) client.c -o $(NAME_c)
		
server : server.c
		$(CC) $(CFLAGS) server.c -o $(NAME_s)

all : $(NAME_s) $(NAME_c)

clean:
	$(RM) $(Obj) 

fclean: clean
	$(RM) $(NAME_s) $(NAME_c)
	

re: fclean all

.PHONY: all clean fclean re