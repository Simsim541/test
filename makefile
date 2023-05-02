# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberri <mberri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 18:48:19 by mberri            #+#    #+#              #
#    Updated: 2023/04/26 19:00:58 by mberri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

NAME=cub3D

CFLAGS=-Wall -Wextra -Werror 

SRCS= main.c		\
	gnl.c			\
	gnl_utils.c		\
	paint.c			\
	utils.c			\
	ft_raycasting.c \
	key.c			\
	
BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS)
		CC $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit $(OBJCTS) -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
		rm -f $(NAME)
		
re: fclean all