# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 14:16:07 by aessabir          #+#    #+#              #
#    Updated: 2021/12/16 14:13:19 by aessabir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = get_next_line.c get_next_line_utils.c check_map.c map_draw.c moving.c main.c
OBJ = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL  -framework AppKit
NAME = so_long


all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) $(MFLAGS) $(OBJ) -o $(NAME) 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all