# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/31 12:34:30 by quroulon          #+#    #+#              #
#    Updated: 2016/04/19 12:45:32 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	game_2048

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

SRC			=	main.c \
				totheleft.c \
				totheright.c \
				tothetop.c \
				tothebottom.c \
				print_tab.c \
				ft_top.c \
				ft_left.c \
				ft_right.c \
				ft_bottom.c \
				all_empty.c \
				put_color.c \
				check_win_value.c \
				key_analyse.c \
				rand_tab.c

LIB			=	libft/libft.a -lncurses

OBJ			=	$(SRC:.c=.o)

HEADER		=	libft/libft.h game.h

all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	cd libft/ && $(MAKE)
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	cd libft/ && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gch

.SILENT : fclean
fclean: clean
	cd libft/ && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all
