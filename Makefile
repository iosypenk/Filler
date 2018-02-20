# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iosypenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 14:59:35 by iosypenk          #+#    #+#              #
#    Updated: 2018/02/07 14:59:40 by iosypenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iosypenk.filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = ./filler.o filler2.o

LIBFT = ./libft/libft.a

.PHONY: libft

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

libft:
	make -C ./libft

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

clean:
	rm -f $(OBJ)
	make clean -C ./libft
	rm -f filler.trace

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
